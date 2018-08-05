#include<iostream>
#include<string>
#include<fstream>

#include "Callback.h"

using namespace std;

#ifndef FileEventListner_H
#define FileEventListner_H

class FileEventListner : public Callback
{
	private:
		std::ofstream m_outPutFileStream;

	public:
		FileEventListner(const std::string& fileName)
		{ 
			m_outPutFileStream.open(fileName);
		}

		void onTick(const std::pair<std::string, std::string>& pairRef)
		{
			m_outPutFileStream << "recieved an event with key = " << pairRef.first << " , and value = " << pairRef.second << '\n';
		}

		void onStale()
		{
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

