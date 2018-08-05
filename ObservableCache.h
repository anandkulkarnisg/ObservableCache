#include<iostream>
#include<string>
#include<algorithm>

#include "StreamEventListner.h"
#include "ThreadSafeCache.h"
#include "FileEventListner.h"
#include "Callback.h"

using namespace std;

#ifndef ObservableCache_H
#define ObservableCache_H

class ObservableCache : private boost::noncopyable
{
	private:
		ThreadSafeCache m_internalCache;							// This is the thread safe cache that allows multiple readers and writers. Implemented using shared_lock / reader-writer lock.	
		std::shared_mutex m_mutex;									// This is used to synchronize the register and deregister of observers which need notification.		
		int m_eventListnerSize;										// Reserve the size of event listners.
		std::vector<std::weak_ptr<Callback>> m_eventListners;		// Used to store the the observers. We store weak references so that we dont encounter lapsed listner problem. 
		
	public:
		ObservableCache(const int&);								// Default constructor.
		void subscribe(const std::weak_ptr<Callback>&);				// The observers can register for events. everytime there is an update to cache it is published to the event Listners.
		bool unsubscribe(const std::shared_ptr<Callback>&);			// Remove or unsubscribe a listner.
		int evict();												// Periodically evict/remove lapsed listners.
		std::string get(const std::string&);						// get an Item from Cache.
		bool put(const std::pair<std::string, std::string>&);		// put an item into Cache. Then alert the listners.
		size_t size() const;										// Get the size of the cache.
		int observerCount();										// Active observers count at any given time.
};

#endif
