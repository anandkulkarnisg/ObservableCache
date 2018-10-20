#include<iostream>
#include<string>
#include<memory>

#include "StreamEventListner.h"
#include "FileEventListner.h"

using namespace std;

int main(int argc, char* argv[])
{
	shared_ptr<Callback> testPtr(new StreamEventListner<string, string>());
	testPtr->onTick(make_pair<string, string>("Anand", "Apparao Kulkarni"));   	

	shared_ptr<Callback> testPtr1(new StreamEventListner<string, string>());
	testPtr1->onTick(make_pair<string, string>("Anand", "Peter Thomas"));

	if(*testPtr.get() == *testPtr.get())
		cout << "Yes they are the same!!" << endl;

	shared_ptr<Callback> testPtr2(new FileEventListner<string, string>("output.txt"));
	testPtr2->onTick(make_pair("Anand","This is a sample message!!"));

	

	return(0);
}
