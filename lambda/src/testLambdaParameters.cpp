#include <iostream>

#include "utils.h"
#include "testLambdaParameters.h"

void testLambdaParameters()
{
	PRINT_SCOPE;

	// This lambda accepts input parameter and prints it
	auto func = [](int p) { std::cout << p << " " << std::endl; };

	// pass something and call...
	func(1234);

	// pass something and call again...
	func(5678);

	// This lambda is being called directly in declaration place
	[](int p) { std::cout << p << " " << std::endl; }(12345678);
}




