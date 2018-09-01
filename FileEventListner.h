#include<iostream>
#include<string>
#include<fstream>
#include<mutex>

#include "Callback.h"

using namespace std;

#ifndef FileEventListner_H
#define FileEventListner_H

template<typename T1, typename T2> class FileEventListner : public Callback
{
	private:
		std::ofstream m_outPutFileStream;
		std::mutex m_mutex;						// Added the mutex so that the onTick can handle events properly without threads overrunning each other.

	public:
		FileEventListner(const std::string& fileName)
		{ 
			m_outPutFileStream.open(fileName);
		}

		void onTick(const std::pair<T1, T2>& pairRef)
		{
			std::lock_guard<std::mutex> lock(m_mutex);
			m_outPutFileStream << "recieved an event with key = " << pairRef.first << " , and value = " << pairRef.second << '\n';
		}

		void onStale()
		{
			std::lock_guard<std::mutex> lock(m_mutex);
			m_outPutFileStream << "recived a stale event from the publishing thread." << '\n';
		}

		bool operator==(const Callback& other)
		{
			return(this == &other);
		}

		~FileEventListner() 
		{
			m_outPutFileStream << std::endl; 
			m_outPutFileStream.close(); 
		}
};

#endif 

