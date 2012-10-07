#include <iostream>
#include "testLambdaDeclaration.h"
#include "testLambdaParameters.h"
#include "testVariableCapture.h"
#include "testFunctor.h"


int main()
{
	testLambdaDeclaration();
	testLambdaParameters();
	testVariableCapture();
	testFunctor();

	return 0;
}

