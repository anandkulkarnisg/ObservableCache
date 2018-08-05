#include<iostream>
#include<string>
#include<utility>

using namespace std;

#ifndef Callback_H
#define Callback_H

class Callback
{
	public:
		virtual void onTick(const std::pair<std::string, std::string>&) = 0;
		virtual void onStale() = 0;
		virtual bool operator==(const Callback&) = 0;
};

#endif
