#include<iostream>
#include<string>

#include "ObservableCache.h"

using namespace std;

// Implement the constructor for the ObservableCache.
template<typename T1, typename T2> ObservableCache<T1,T2>::ObservableCache()
{ 

} 

// Implement subscribe method. 
template<typename T1, typename T2> void ObservableCache<T1,T2>::subscribe(const weak_ptr<Callback>& eventListner)
{
	{
		// Take a mutex Lock and insert the eventListner into the vector.
		unique_lock<shared_mutex> lock(m_mutex);

		// Push the item.
		auto sp = eventListner.lock();	
		string eventListnerKey = sp->getId();
		m_eventListners[eventListnerKey]=eventListner;
	}

}

// Implement the unsubscribe method.
template<typename T1, typename T2> bool ObservableCache<T1,T2>::unsubscribe(const shared_ptr<Callback>& eventListner)
{
	// Please note that unsubscribe means the observer is still active. 
	// but it does not want the events anymore. We need to simply remove it from subscription list. 

	string eventListnerKey = eventListner->getId();
	const auto& iter = m_eventListners.find(eventListnerKey);
	if(iter != m_eventListners.end())
	{
		unique_lock<shared_mutex> lock(m_mutex);
		m_eventListners.erase(eventListnerKey);
	}
	else
		return(false);
	return(true);
}

// Implement a method to get an Item from the cache. Else return nullptr.
template<typename T1, typename T2> pair<bool, T2> ObservableCache<T1,T2>::get(const T1& keyItem)
{
	pair<bool, T2> returnItem = m_cache.get(keyItem);
	return(returnItem);
}

// Implement a method to insert/update an item into the Cache. 
template<typename T1, typename T2> bool ObservableCache<T1,T2>::put(const pair<T1 , T2>& pairRef)
{
	bool returnStatus = false;

	if(pairRef.first.empty() || pairRef.second.empty())
		return(returnStatus);

	returnStatus = m_cache.upsert(pairRef);
	if(returnStatus)
	{
		shared_lock<shared_mutex> lock(m_mutex); // Our aim is to publish as fast as possible. It is upto the listner to handle these events incoming via onTick as fast as possible.
		for(const auto& iter : m_eventListners)
		{
			if(!iter.second.expired())
			{
				auto sp = iter.second.lock();	// Double check if iter expiry needed as weak_ptr expired false indication may turn out to be racy in multi threaded code.
				if(!iter.second.expired())
				{
					sp->onTick(pairRef);	
				}
			}
		}	
		lock.unlock();
	}
	return(returnStatus);
}

// Implement a method to remove an item from the cache via the key.
template<typename T1, typename T2> bool ObservableCache<T1,T2>::erase(const T1& keyItem)
{
	bool returnStatus = m_cache.erase(keyItem);
	return(returnStatus);
}

// Implement the eviction policy. This may be run by the application in a seperate thread. It returns to the caller how many lapsed listners were cleaned up.
template<typename T1, typename T2> int ObservableCache<T1,T2>::evict()
{
	int lapseCount=0;
	// We need a exclusive write lock on the m_eventListners to clean it up.
	unique_lock<shared_mutex> lock(m_mutex);
	for(const auto& iter : m_eventListners)
	{
		if(iter.second.expired())
		{
			m_eventListners.erase(iter.first);
			++lapseCount;
		}
	}
	lock.unlock();
	return(lapseCount);
}

// return the size of the Internal cache.
template<typename T1, typename T2> size_t ObservableCache<T1,T2>::size() const
{
	return(m_cache.size());
}

// Return the size of the observers count.
template<typename T1, typename T2> int ObservableCache<T1,T2>::observerCount()
{
	shared_lock<shared_mutex> lock(m_mutex);
	return(m_eventListners.size());
}

template class ObservableCache<string, string>;
