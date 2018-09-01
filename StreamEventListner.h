#include<iostream>
#include<string>
#include<mutex>

#include "Callback.h"

using namespace std;

#ifndef StreamEventListner_H
#define StreamEventListner_H

template<typename T1, typename T2> class StreamEventListner : public Callback
{
	private:
			std::mutex m_mutex;						// Since output stream needs ordered display , added a mutex to manage the synchronization.

	public:

		void onTick(const std::pair<T1, T2>& pairRef)
		{
			std::lock_guard<std::mutex> lock(m_mutex);
			std::cout << "recieved an event with key = " << pairRef.first << " , and value = " << pairRef.second << std::endl;
		}

		void onStale()
		{
			std::lock_guard<std::mutex> lock(m_mutex);
			std::cout << "recived a stale event from the publishing thread." << std::endl;
		}

		bool operator==(const Callback& other)
		{
			return(this == &other);
		}
};

#endif 

