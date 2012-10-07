#include <iostream>

#include "utils.h"
#include "testLambdaDeclaration.h"

void testLambdaDeclaration()
{
	PRINT_SCOPE;

	// This lambda does nothing
	[](){}();

	// This lambda prints message
	[](){ std::cout << "Hello from C++ lambda 1!" << std::endl; }();

	// This lambda is assigned to variable
	auto lambda = [](){ std::cout << "Hello from C++ lambda 2!" << std::endl; };

	// and is being called...
	lambda();
}



