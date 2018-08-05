#include<iostream>
#include<string>
#include<memory>
#include<thread>
#include<memory>
#include<chrono>

#include "ThreadSafeCache.h"

using namespace std;

std::shared_ptr<ThreadSafeCache> ptr(new ThreadSafeCache);
int i=0;

void funcWrite()
{
	std::string result;
	while(i<100)
	{
		result=ptr->get("Anand");
		if(result == "Apparao Kulkarni")
			ptr->upsert(std::make_pair<std::string, std::string>("Anand", "Peter Thomas"));
		if(result == "Peter Thomas")
			ptr->upsert(std::make_pair<std::string, std::string>("Anand", "Albert Decosta"));		
		if(result == "Albert Decosta")
			ptr->upsert(std::make_pair<std::string, std::string>("Anand", "Apparao Kulkarni"));

		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		++i;
	}			
}

void funcRead()
{
	std::string result;
	while(i<100)
	{
		result = ptr->get("Anand");
		std::cout << "The result item from thread id = " << std::this_thread::get_id() << " is = " << result << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}

int main(int argc, char* argv[])
{
	ptr->upsert(std::make_pair("Anand", "Apparao Kulkarni"));
	std::thread t1(funcWrite);
	std::thread t2(funcRead);	
	std::thread t3(funcRead);
	std::thread t4(funcWrite);

	t1.join();
	t2.join();	
	t3.join();
	t4.join();

	return(0);
}
