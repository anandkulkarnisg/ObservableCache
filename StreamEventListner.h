#include<iostream>
#include<string>

#include "Callback.h"

using namespace std;

#ifndef StreamEventListner_H
#define StreamEventListner_H

class StreamEventListner : public Callback
{
	public:

		void onTick(const std::pair<std::string, std::string>& pairRef)
		{
			std::cout << "recieved an event with key = " << pairRef.first << " , and value = " << pairRef.second << std::endl;
		}

		void onStale()
		{
			std::cout << "recived a stale event from the publishing thread." << std::endl;
		}

		bool operator==(const Callback& other)
		{
			return(this == &other);
		}
};

#endif 

