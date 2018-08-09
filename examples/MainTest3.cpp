#include<iostream>
#include<string>
#include<thread>
#include<memory>
#include<chrono>

#include "ObservableCache.h"

using namespace std;

ObservableCache<std::string, std::string> cache(10);
bool finish = false;
bool mainWait = false;

void writeToCache(const std::string& seed, const long& count)
{
	std::string sampleStr;
	for(unsigned int i=0 ; i<count; ++i)
	{
		sampleStr = seed + std::to_string(i);
		cache.put(std::make_pair(sampleStr, "test value"));
		std::cout << "Thread id = " << std::this_thread::get_id() << " : Finished adding the item." << std::endl;
	}
}

void addEventSubscriptions()
{
	std::shared_ptr<Callback> listner(new FileEventListner("ping.txt"));
	cache.subscribe(listner);
	mainWait = true;
	while(finish != true)
	{

	}
}

int main(int argc, char* argv[])
{
	std::thread t3(&addEventSubscriptions);
	while(!mainWait)
	{

	}
	std::vector<std::string> vec = { "Anand" , "Peter", "Thomas" , "Albert", "Jacob", "Mike", "Jake", "Nigel", "Jeremy", "Louis" };
	std::vector<std::thread> threads;
	threads.reserve(10);
	for(unsigned int i=0; i<10; ++i)
		threads.push_back(std::thread(&writeToCache, vec[i], 1000000));
	std::for_each(threads.begin(), threads.end(), [&](std::thread& t){ t.join(); });
	finish=true;
	t3.join();
	std::cout << "Finished adding total of " << cache.size() << " items into the cache." << std::endl;
	return(0);
}

