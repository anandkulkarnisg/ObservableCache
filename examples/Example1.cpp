#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char* argv[])
{
	//vector<int> vec = { 1, 2, 1, 3, 1, 1, 1, 2, 1 };
	vector<int> vec = { };
	cout << "before size = " << vec.size() << endl;
	vec.erase(remove_if(vec.begin(), vec.end(), [](const int& item) { return(item == 1); }), vec.end());
	cout << "after size = " << vec.size() << endl;
	return(0);
}
