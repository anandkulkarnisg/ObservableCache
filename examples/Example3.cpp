#include<iostream>
#include<string>
#include<thread>
#include<memory>
#include<chrono>

#include "ObservableCache.h"

using namespace std;

ObservableCache<string, string> cache(10);
bool finish = false;

void writeToCache(const string& seed, const long& count)
{
	string sampleStr;
	for(unsigned int i=0 ; i<count; ++i)
	{
		sampleStr = seed + to_string(i);
		cache.put(make_pair(sampleStr, "test value"));
		cout << "Thread id = " << this_thread::get_id() << " : Finished adding the item." << endl;
	}
}

void addEventSubscriptions()
{
	shared_ptr<Callback> listner1(new StreamEventListner<string, string>());
	shared_ptr<Callback> listner2(new FileEventListner<string, string>("output.txt"));
	shared_ptr<Callback> listner3(new FileEventListner<string, string>("output2.txt"));

	cache.subscribe(listner1);
	cache.subscribe(listner2);
	cache.subscribe(listner3);
	
	while(finish != true)
	{

	}
}

int main(int argc, char* argv[])
{
	thread t3(&addEventSubscriptions);
	thread t1(&writeToCache, "Anand", 1000000);
	thread t2(&writeToCache, "Peter", 5000000);

	t1.join();
	t2.join();
	finish = true;
	t3.join();

	cout << "Finished adding total of " << cache.size() << " items into the cache." << endl;
	return(0);
}

