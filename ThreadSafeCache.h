#include<iostream>
#include<string>
#include<shared_mutex>
#include<mutex>
#include<thread>
#include<vector>
#include<memory>
#include<map>
#include <boost/core/noncopyable.hpp>

#include "Callback.h"
#include "ThreadPool.h"

using namespace std;

#ifndef ThreadSafeCache_H
#define ThreadSafeCache_H

class ThreadSafeCache : private boost::noncopyable
{
	private:
		std::map<std::string, std::string> m_InternalThreadSafeCache;
		mutable std::shared_mutex m_readWriteMutex;

	public:
		ThreadSafeCache();													// Default constructor.	
		bool upsert(const std::pair<std::string, std::string>&);		    // This method is used to update the cache , returns a status if update was successfull / fail.
		std::string get(const std::string&);								// get an Item from cache in read only mode.
		size_t size() const;												// return the size of map.
};

#endif
