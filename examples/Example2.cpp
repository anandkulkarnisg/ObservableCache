#include<iostream>
#include<string>

#include "ObservableCache.h"

using namespace std;

ObservableCache<string, string> testCache;

int main(int argc, char* argv[])
{
	shared_ptr<Callback> streamEventListner(new StreamEventListner<string, string>());
	shared_ptr<Callback> fileEventListner(new FileEventListner<string, string>("output.txt"));
	shared_ptr<Callback> fileEventListner2(new FileEventListner<string, string>("output2.txt"));

	testCache.subscribe(streamEventListner);
	testCache.subscribe(fileEventListner);
	testCache.subscribe(fileEventListner2);

	testCache.put(make_pair("Anand", "Peter Thomas"));
	testCache.put(make_pair("Anand", "Albert Jacobi"));	

	testCache.unsubscribe(streamEventListner);
	fileEventListner2.reset();
	testCache.put(make_pair("Peter", "Thomas Becker!!"));
	cout << "eviction result = " << testCache.evict() << endl;

	testCache.put(make_pair("bespoke", "Thomas Peter"));
	cout << "cache size = " << testCache.size() << endl;
	cout << "observer size = " << testCache.observerCount() << endl;

	return(0);	
}

