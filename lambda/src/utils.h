#ifndef UTILS_H_
#define UTILS_H_

#include <string>
#include <iostream>

class ScopePrinter
{
public:
	ScopePrinter(std::string scope)
	{
		m_scope = scope;

		printScopeBegin();
	}

	~ScopePrinter()
	{
		printScopeEnd();
	}

private:
	void printScopeBegin()
	{
		std::cout << "------------ BEGIN " << m_scope << " ------------" << std::endl << std::endl;
	}

	void printScopeEnd()
	{
		std::cout << std::endl << "------------ END   " << m_scope << " ------------" << std::endl << std::endl;
	}

private:
	std::string m_scope;
};

#define PRINT_SCOPE ScopePrinter scopePrinter = ScopePrinter(__FUNCTION__)


#endif
