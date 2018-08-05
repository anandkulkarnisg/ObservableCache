#include<iostream>
#include<string>
#include<memory>

#include "StreamEventListner.h"
#include "FileEventListner.h"

using namespace std;

int main(int argc, char* argv[])
{
	std::shared_ptr<Callback> testPtr(new StreamEventListner);
	testPtr->onTick(make_pair<std::string, std::string>("Anand", "Apparao Kulkarni"));   	

	std::shared_ptr<Callback> testPtr1(new StreamEventListner);
	testPtr1->onTick(make_pair<std::string, std::string>("Anand", "Peter Thomas"));

	if(*testPtr.get() == *testPtr.get())
		std::cout << "Yes they are the same!!" << std::endl;

	std::shared_ptr<Callback> testPtr2(new FileEventListner("output.txt"));
	testPtr2->onTick(make_pair("Anand","This is a sample message!!"));

	

	return(0);
}
