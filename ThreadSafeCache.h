#include<iostream>
#include<string>
#include<shared_mutex>
#include<mutex>
#include<thread>
#include<vector>
#include<memory>
#include<map>
#include<utility>
#include <boost/core/noncopyable.hpp>

#include "Callback.h"
#include "ThreadPool.h"

using namespace std;

#ifndef ThreadSafeCache_H
#define ThreadSafeCache_H

template<typename T1, typename T2> class ThreadSafeCache : private boost::noncopyable
{
	private:
		std::map<T1, T2> m_cache;
		mutable std::shared_mutex m_mutex;

	public:
		ThreadSafeCache();													// Default constructor.	
		bool upsert(const std::pair<T1, T2>&);							    // This method is used to update the cache , returns a status if update was successfull / fail.
		std::pair<bool, T2> get(const T1&);									// get an Item from cache in read only mode.
		bool erase(const T1&);												// Erase an item from the cache if present. return the status accordingly.
		size_t size() const;												// return the size of map.
};

#endif
