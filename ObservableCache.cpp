#include<iostream>
#include<string>

#include "ObservableCache.h"

using namespace std;

// Implement the constructor for the ObservableCache.
ObservableCache::ObservableCache(const int& eventListnerSize) : m_eventListnerSize(eventListnerSize) 
{ 
	m_eventListners.reserve(m_eventListnerSize);
} 

// Implement subscribe method. 
void ObservableCache::subscribe(const std::weak_ptr<Callback>& eventListner)
{
	// Take a mutex Lock and insert the eventListner into the vector.
	std::unique_lock<std::shared_mutex> lock(m_mutex);

	// Push the item.
	m_eventListners.emplace_back(eventListner);

	// Release the lock.
	lock.unlock();	
}

// Implement the unsubscribe method.
bool ObservableCache::unsubscribe(const std::shared_ptr<Callback>& eventListner)
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
std::string ObservableCache::get(const std::string& keyItem)
{
	if(!keyItem.empty())
		return(m_internalCache.get(keyItem));
	else
		return("");
}

// Implement a method to insert/update an item into the Cache. 
bool ObservableCache::put(const std::pair<std::string , std::string>& pairRef)
{
	bool returnStatus = false;

	if(pairRef.first.empty() || pairRef.second.empty())
		return(returnStatus);

	returnStatus = m_internalCache.upsert(pairRef);
	if(returnStatus)
	{
		std::shared_lock<std::shared_mutex> lock(m_mutex);
		for(const auto& iter : m_eventListners)
		{
			if(!iter.expired())
			{
				auto sp = iter.lock();
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
int ObservableCache::evict()
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
size_t ObservableCache::size() const
{
	return(m_internalCache.size());
}

// Return the size of the observers count.
int ObservableCache::observerCount()
{
	std::shared_lock<std::shared_mutex> lock(m_mutex);
	return(m_eventListners.size());
}

