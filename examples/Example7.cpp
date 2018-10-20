#include<iostream>
#include<string>
#include<memory>
#include<thread>
#include<memory>
#include<chrono>

#include "ThreadSafeCache.h"

using namespace std;

shared_ptr<ThreadSafeCache<string, string>> ptr(new ThreadSafeCache<string, string>);
int i=0;

void funcWrite()
{
	string result;
	while(i<100)
	{
		result=ptr->get("Anand");
		if(result == "Apparao Kulkarni")
			ptr->upsert(make_pair<string, string>("Anand", "Peter Thomas"));
		if(result == "Peter Thomas")
			ptr->upsert(make_pair<string, string>("Anand", "Albert Decosta"));		
		if(result == "Albert Decosta")
			ptr->upsert(make_pair<string, string>("Anand", "Apparao Kulkarni"));

		this_thread::sleep_for(chrono::milliseconds(500));
		++i;
	}			
}

void funcRead()
{
	string result;
	while(i<100)
	{
		result = ptr->get("Anand");
		cout << "The result item from thread id = " << this_thread::get_id() << " is = " << result << endl;
		this_thread::sleep_for(chrono::milliseconds(100));
	}
}

int main(int argc, char* argv[])
{
	ptr->upsert(make_pair("Anand", "Apparao Kulkarni"));
	thread t1(funcWrite);
	thread t2(funcRead);	
	thread t3(funcRead);
	thread t4(funcWrite);

	t1.join();
	t2.join();	
	t3.join();
	t4.join();

	return(0);
}
