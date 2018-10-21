#include<iostream>
#include<string>
#include<utility>
#include<sstream>

using namespace std;

#ifndef Callback_H
#define Callback_H

class Callback
{
	public:
		virtual void onTick(const std::pair<std::string, std::string>&) = 0;
		virtual void onStale() = 0;
		virtual bool operator==(const Callback&) = 0;
		string getId()
		{
			const void * address = static_cast<const void*>(this);
			stringstream stream;
			stream << address;
			string id = "observer:" + stream.str();
			return(id);
		}
};

#endif
