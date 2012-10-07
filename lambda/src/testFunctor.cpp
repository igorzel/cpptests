#include <iostream>
#include <list>
#include <algorithm>

#include "utils.h"
#include "testFunctor.h"

//-------------------------------------------------------------------

class MyFunctor
{
public:
	void operator() (int p)
	{
		std::cout << p << " ";
	}
};

//-------------------------------------------------------------------

void testFunctor()
{
	PRINT_SCOPE;

	std::list<int> objects;
	const int size = 10;

	for (int i=0; i<size; ++i)
	{
		objects.push_back(i);
	}

	std::for_each(objects.begin(), objects.end(), MyFunctor());
	std::cout << std::endl;

	std::for_each(objects.begin(), objects.end(), [](int p){ std::cout << p << " "; });
	std::cout << std::endl;
}

