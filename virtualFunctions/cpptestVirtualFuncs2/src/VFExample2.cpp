#include <iostream>


class A
{
public:
	int x;

	void m1() {}
	void m2() {}
};

class B
{
public:
	virtual ~B() {}

	int x;

	void m1() {}
	void m2() {}
	virtual void vm1() {}
	virtual void vm2() {}
};


int main()
{
	A obj1;
	obj1.x = 0x12345678;

	std::cout << "sizeof(obj1)=" << sizeof(obj1) << std::endl;


	B obj2;
	obj2.x = 0x12345678;

	std::cout << "sizeof(obj2)=" << sizeof(obj2) << std::endl;

	return 0;
}
