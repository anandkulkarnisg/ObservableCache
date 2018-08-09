#include<iostream>
#include<string>

#include "ObservableCache.h"

using namespace std;

// Implement the constructor for the ObservableCache.
template<typename T1, typename T2> ObservableCache<T1,T2>::ObservableCache(const int& eventListnerSize) : m_eventListnerSize(eventListnerSize) 
{ 
	m_eventListners.reserve(m_eventListnerSize);
} 

// Implement subscribe method. 
template<typename T1, typename T2> void ObservableCache<T1,T2>::subscribe(const std::weak_ptr<Callback>& eventListner)
{
	// Take a mutex Lock and insert the eventListner into the vector.
	std::unique_lock<std::shared_mutex> lock(m_mutex);

	// Push the item.
	m_eventListners.emplace_back(eventListner);

	// Release the lock.
	lock.unlock();	
}

// Implement the unsubscribe method.
template<typename T1, typename T2> bool ObservableCache<T1,T2>::unsubscribe(const std::shared_ptr<Callback>& eventListner)
{
	// Please note that unsubscribe means the observer is still active. 
	// but it does not want the events anymore. We need to simply remove it from subscription list. 
	bool isFound = false;
	int idx = 0;

	// We need a lock around the vector before proceeding further.
	std::unique_lock<std::shared_mutex> lock(m_mutex);
	for(const auto& iter : m_eventListners)
	{
		if(!iter.expired())
		{
			auto sp = iter.lock();
			if(!iter.expired())
			{
				if(*sp.get() == *eventListner.get())
				{
					isFound=true;
					break;
				}
			}	
		}
		++idx;
	}

	if(isFound)
	{
		m_eventListners.erase(m_eventListners.begin() + idx);
	}
	lock.unlock();
	return(isFound);
}

// Implement a method to get an Item from the cache. Else return nullptr.
template<typename T1, typename T2> T2 ObservableCache<T1,T2>::get(const T1& keyItem)
{
	if(!keyItem.empty())
		return(m_internalCache.get(keyItem));
	else
		return("");
}

// Implement a method to insert/update an item into the Cache. 
template<typename T1, typename T2> bool ObservableCache<T1,T2>::put(const std::pair<T1 , T2>& pairRef)
{
	bool returnStatus = false;

	if(pairRef.first.empty() || pairRef.second.empty())
		return(returnStatus);

	returnStatus = m_internalCache.upsert(pairRef);
	if(returnStatus)
	{
		std::shared_lock<std::shared_mutex> lock(m_mutex); // Our aim is to publish as fast as possible. It is upto the listner to handle these events incoming via onTick as fast as possible.
		for(const auto& iter : m_eventListners)
		{
			if(!iter.expired())
			{
				auto sp = iter.lock();	// Double check if iter expiry needed as weak_ptr expired false indication may turn out to be racy in multi threaded code.
				if(!iter.expired())
				{
					sp->onTick(pairRef);	
				}
			}
		}	
		lock.unlock();
	}
	return(returnStatus);
}

// Implement the eviction policy. This may be run by the application in a seperate thread. It returns to the caller how many lapsed listners were cleaned up.
template<typename T1, typename T2> int ObservableCache<T1,T2>::evict()
{
	int lapseCount=0;
	// We need a exclusive write lock on the m_eventListners to clean it up.
	std::unique_lock<std::shared_mutex> lock(m_mutex);
	int startSize = m_eventListners.size();
	m_eventListners.erase(std::remove_if(m_eventListners.begin(), m_eventListners.end(), [&](const std::weak_ptr<Callback>& ptr){return ptr.expired();}), m_eventListners.end());
	int endSize = m_eventListners.size();
	lock.unlock();
	lapseCount=startSize-endSize;
	return(lapseCount);
}

// return the size of the Internal cache.
template<typename T1, typename T2> size_t ObservableCache<T1,T2>::size() const
{
	return(m_internalCache.size());
}

// Return the size of the observers count.
template<typename T1, typename T2> int ObservableCache<T1,T2>::observerCount()
{
	std::shared_lock<std::shared_mutex> lock(m_mutex);
	return(m_eventListners.size());
}

template class ObservableCache<std::string, std::string>;
