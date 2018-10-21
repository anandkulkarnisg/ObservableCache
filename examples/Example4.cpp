#include<iostream>
#include<string>
#include<thread>
#include<memory>
#include<chrono>

#include "ObservableCache.h"

using namespace std;

ObservableCache<string, string> cache;
bool finish = false;
bool mainWait = false;

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
	shared_ptr<Callback> listner(new FileEventListner<string, string>("ping.txt"));
	cache.subscribe(listner);
	mainWait = true;
	while(finish != true)
	{

	}
}

int main(int argc, char* argv[])
{
	thread t3(&addEventSubscriptions);
	while(!mainWait)
	{

	}
	vector<string> vec = { "Anand" , "Peter", "Thomas" , "Albert", "Jacob", "Mike", "Jake", "Nigel", "Jeremy", "Louis" };
	vector<thread> threads;
	threads.reserve(10);
	for(unsigned int i=0; i<10; ++i)
		threads.push_back(thread(&writeToCache, vec[i], 1000000));
	for_each(threads.begin(), threads.end(), [&](thread& t){ t.join(); });
	finish=true;
	t3.join();
	cout << "Finished adding total of " << cache.size() << " items into the cache." << endl;
	return(0);
}

