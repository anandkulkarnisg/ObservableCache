#include<iostream>
#include<string>
#include<thread>
#include<memory>
#include<chrono>

#include "ObservableCache.h"

using namespace std;

ObservableCache cache(10);
bool finish = false;

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
	std::shared_ptr<Callback> listner1(new StreamEventListner);
	std::shared_ptr<Callback> listner2(new FileEventListner("output.txt"));
	std::shared_ptr<Callback> listner3(new FileEventListner("output2.txt"));

	cache.subscribe(listner1);
	cache.subscribe(listner2);
	cache.subscribe(listner3);
	
	while(finish != true)
	{

	}
}

int main(int argc, char* argv[])
{
	std::thread t3(&addEventSubscriptions);
	std::thread t1(&writeToCache, "Anand", 1000000);
	std::thread t2(&writeToCache, "Peter", 5000000);

	t1.join();
	t2.join();
	finish = true;
	t3.join();

	std::cout << "Finished adding total of " << cache.size() << " items into the cache." << std::endl;

}

