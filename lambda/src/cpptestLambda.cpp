//============================================================================
// Name        : cpptestLambda.cpp
// Author      : svarozhych
// Version     :
// Copyright   : svarozhych(c)
// Description : Examples of lambda usage in C++
//============================================================================

#include <iostream>

int main()
{
	[](){ std::cout << "Hello from C++ lambda!" << std::endl; }();

	return 0;
}

