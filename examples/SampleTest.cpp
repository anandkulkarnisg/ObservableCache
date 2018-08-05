#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char* argv[])
{
	//std::vector<int> vec = { 1, 2, 1, 3, 1, 1, 1, 2, 1 };
	std::vector<int> vec = { };
	std::cout << "before size = " << vec.size() << std::endl;
	vec.erase(std::remove_if(vec.begin(), vec.end(), [](const int& item) { return(item == 1); }), vec.end());
	std::cout << "after size = " << vec.size() << std::endl;
	return(0);
}
