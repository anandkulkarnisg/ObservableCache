#include<iostream>
#include<string>

#include "ThreadSafeCache.h"

using namespace std;

// Constructor implementation.
ThreadSafeCache::ThreadSafeCache()
{

}

// Get Function to get an item from the ThreadSafeCache. returns the value of a key if this is present in the cache.
std::string ThreadSafeCache::get(const std::string& keyItem)
{
	// Take a read only lock and then try to identify if the item is present in the cache.
	std::shared_lock<std::shared_mutex> lock(m_readWriteMutex);	

	auto iter = m_InternalThreadSafeCache.find(keyItem);
	if( iter != m_InternalThreadSafeCache.end())
	{
		lock.unlock();
		return(iter->second);		
	}

	return(nullptr);
}

// Method that does the cache update with a given item.
bool ThreadSafeCache::upsert(const std::pair<std::string, std::string>& upsertItem)
{
	// Attempt to insert the item into the cache. If the key is found then check the value. If both are same then reject. If the value is updated/new then accept and update the cache.
	// First of all check if the cache has the item and if the value is also same. Else only proceed.

	bool updateRequired = false;	

	// First take a read only lock and check if the item is present and if they kev/value are same. Then decide to take exclusive lock and update the item.
	std::shared_lock<std::shared_mutex> lock(m_readWriteMutex);

	auto iter = m_InternalThreadSafeCache.find(upsertItem.first);
	if( iter == m_InternalThreadSafeCache.end())
	{
		updateRequired = true;	
	}	
	else
	{
		if(!(iter->first == upsertItem.first && iter->second == upsertItem.second))
		{
			updateRequired = true;
		} 
	}

	lock.unlock();

	// Attempt an exclusive write lock now to update the content only if the updateRequired is true.
	if(updateRequired)
	{
		std::unique_lock<std::shared_mutex> writeLock(m_readWriteMutex);
		m_InternalThreadSafeCache[upsertItem.first] = upsertItem.second;
	}	

	return(updateRequired);
}

size_t ThreadSafeCache::size() const
{
	std::shared_lock<std::shared_mutex> lock(m_readWriteMutex);
	return(m_InternalThreadSafeCache.size());	
}
