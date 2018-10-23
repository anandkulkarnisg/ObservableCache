#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<sstream>
#include<utility>

#include "StreamEventListner.h"
#include "ThreadSafeCache.h"
#include "FileEventListner.h"
#include "Callback.h"

using namespace std;

#ifndef ObservableCache_H
#define ObservableCache_H

template<typename T1, typename T2> class ObservableCache : private boost::noncopyable
{
	private:
		ThreadSafeCache<T1,T2> m_cache;						// This is the thread safe cache that allows multiple readers and writers. Implemented using shared_lock / reader-writer lock.	
		std::shared_mutex m_mutex;									// This is used to synchronize the register and deregister of observers which need notification.		
		std::map<std::string, std::weak_ptr<Callback>> m_eventListners;	// Used to store the the observers. We store weak references so that we dont encounter lapsed listner problem. 
	
	public:
		ObservableCache();											// Default constructor.
		void subscribe(const std::weak_ptr<Callback>&);				// The observers can register for events. everytime there is an update to cache it is published to the event Listners.
		bool unsubscribe(const std::shared_ptr<Callback>&);			// Remove or unsubscribe a listner.
		int evict();												// Periodically evict/remove lapsed listners.
		std::pair<bool,T2> get(const T1&);							// get an Item from Cache.
		bool put(const std::pair<T1, T2>&);							// put an item into Cache. Then alert the listners.
		bool erase(const T1&);										// remove an item from the ThreadSafe Cache.
		size_t size() const;										// Get the size of the cache.
		int observerCount();										// Active observers count at any given time.
};

#endif

