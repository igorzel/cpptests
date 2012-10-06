#include <iostream>

class Animal
{
public:
	Animal() { std::cout << "Animal::Animal" << std::endl; }
	virtual ~Animal() { std::cout << "Animal::~Animal" << std::endl; }
	virtual void DoSound() {}
};

class Cat : public Animal
{
public:
	Cat() { std::cout << "Cat::Cat" << std::endl; }
	~Cat() { std::cout << "Cat::~Cat" << std::endl; }
	void DoSound() { std::cout << "Mew!" << std::endl; }
};

class Dog : public Animal
{
public:
	Dog() { std::cout << "Dog::Dog" << std::endl; }
	~Dog() { std::cout << "Dog::~Dog" << std::endl; }
	void DoSound() { std::cout << "Wow" << std::endl; }
};

class Frog : public Animal
{
public:
	Frog() { std::cout << "Frog::Frog" << std::endl; }
	~Frog() { std::cout << "Frog::~Frog" << std::endl; }
	void DoSound() { std::cout << "Croc!" << std::endl; }
};

int main()
{
	Animal* animal1 = new Cat();
	Animal* animal2 = new Dog();
	Animal* animal3 = new Frog();

	animal1->DoSound();
	animal2->DoSound();
	animal3->DoSound();

	delete animal1;
	delete animal2;
	delete animal3;

	return 0;
}
