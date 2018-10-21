#include<iostream>
#include<string>

#include "ThreadSafeCache.h"

using namespace std;

// Constructor implementation.
template<typename T1, typename T2> ThreadSafeCache<T1,T2>::ThreadSafeCache()
{

}

// Get Function to get an item from the ThreadSafeCache. returns the value of a key if this is present in the cache.
template<typename T1, typename T2> pair<bool, T2> ThreadSafeCache<T1,T2>::get(const T1& keyItem)
{
	// Take a read only lock and then try to identify if the item is present in the cache.
	shared_lock<shared_mutex> lock(m_readWriteMutex);	

	auto iter = m_InternalThreadSafeCache.find(keyItem);
	if( iter != m_InternalThreadSafeCache.end())
	{
		lock.unlock();
		return(make_pair(true, iter->second));
	}

	return(make_pair(false, nullptr));
}

// Method that does the cache update with a given item.
template<typename T1, typename T2> bool ThreadSafeCache<T1,T2>::upsert(const pair<T1, T2>& upsertItem)
{
	// Attempt to insert the item into the cache. If the key is found then check the value. If both are same then reject. If the value is updated/new then accept and update the cache.
	// First of all check if the cache has the item and if the value is also same. Else only proceed.

	bool updateRequired = false;	

	// First take a read only lock and check if the item is present and if they kev/value are same. Then decide to take exclusive lock and update the item.
	shared_lock<shared_mutex> lock(m_readWriteMutex);

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
		unique_lock<shared_mutex> writeLock(m_readWriteMutex);
		m_InternalThreadSafeCache[upsertItem.first] = upsertItem.second;
	}	

	return(updateRequired);
}

template<typename T1, typename T2> size_t ThreadSafeCache<T1,T2>::size() const
{
	shared_lock<shared_mutex> lock(m_readWriteMutex);
	return(m_InternalThreadSafeCache.size());	
}

template class ThreadSafeCache<string, string>;
