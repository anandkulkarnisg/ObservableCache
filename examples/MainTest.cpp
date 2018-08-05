#include<iostream>
#include<string>

#include "ObservableCache.h"

using namespace std;

ObservableCache testCache(10);

int main(int argc, char* argv[])
{
	std::shared_ptr<Callback> streamEventListner(new StreamEventListner);
	std::shared_ptr<Callback> fileEventListner(new FileEventListner("output.txt"));
	std::shared_ptr<Callback> fileEventListner2(new FileEventListner("output2.txt"));

	testCache.subscribe(streamEventListner);
	testCache.subscribe(fileEventListner2);
	testCache.subscribe(fileEventListner);

	testCache.unsubscribe(streamEventListner);
	testCache.unsubscribe(fileEventListner);
	testCache.unsubscribe(fileEventListner2);	
	
	/*
	streamEventListner.reset();
	fileEventListner.reset();
	fileEventListner2.reset();
	*/

	testCache.put(std::make_pair("Anand", "Peter Thomas"));
	testCache.put(std::make_pair("Anand", "Albert Jacobi"));	
	testCache.put(std::make_pair("Peter", "Thomas Becker!!"));

	std::cout << "eviction result = " << testCache.evict() << std::endl;

	testCache.put(std::make_pair("bespoke", "Thomas Peter"));
	std::cout << "cache size = " << testCache.size() << std::endl;
	std::cout << "observer size = " << testCache.observerCount() << std::endl;

	return(0);	
}

