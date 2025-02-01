#include "easyfind.hpp"
#include <vector>
#include <list>

int main()
{
	std::vector<int> vector;
	std::list<int> list;
	vector.push_back(10);
	vector.push_back(20);
	vector.push_back(30);
	vector.push_back(99);
	vector.push_back(55);
	vector.push_back(66);
	try
	{
		easyfind(vector, 10);
		easyfind(vector, 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


}
