#include <stdio.h>
#include <stdlib.h>

//-----------------------------------------------------------------------------------------

// Virtual Table of our classes
typedef struct
{
	void (*DoSound)(void);
	void (*Destructor)(void);
} VFTable;

typedef struct ClassAnimal
{
	VFTable *vtable; // pointer to Virtual Methods Table
	int age; // data specific to ClassAnimal
} ClassAnimal;


void ClassAnimal_Destructor(void)
{
	printf("Animal destructor\n");
}

// Virtual Methods Table of ClassAnimal
// ClassAnimal doesn't have DoSound implementation so it set to NULL - pure virtual method
VFTable classAnimalVFtable = { NULL, ClassAnimal_Destructor };


//-----------------------------------------------------------------------------------------

typedef struct ClassCat // : public ClassAnimal
{
	// ClassAnimal part
	VFTable *vtable; // pointer to Virtual Methods Table
	int age; // data specific to ClassAnimal

	// ClassCat part
	int catLivesCounter; // data specific to ClassCat
} ClassCat;


void ClassCat_DoSound(void)
{
	printf("Mew!\n");
}

void ClassCat_Destructor(void)
{
	printf("Cat destructor\n");
}

// Virtual Methods Table of ClassCat
VFTable classCatVFtable = { ClassCat_DoSound, ClassCat_Destructor };

//-----------------------------------------------------------------------------------------

typedef struct ClassFrog // : public ClassAnimal
{
	// ClassAnimal part
	VFTable *vtable; // pointer to Virtual Methods Table
	int age; // data specific to ClassAnimal

	// ClassFrog part
	int jumpDistance; // data specific to ClassFrog
} ClassFrog;


void ClassFrog_DoSound(void)
{
	printf("Crock!\n");
}

void ClassFrog_Destructor(void)
{
	printf("Frog destructor\n");
}

// Virtual Methods Table of ClassFrog
VFTable classFrogVFtable = { ClassFrog_DoSound, ClassFrog_Destructor };

//-----------------------------------------------------------------------------------------



int main(void)
{
	//-----------------------------------------------

	// code in c++:
	//
	// ClassAnimal* animal = new ClassCat();
	// animal->DoSound();
	// delete animal;
	//
	// implementation of this code in c:

	ClassAnimal* animal1 = malloc(sizeof(ClassCat)); // allocate memory for ClassCat
	animal1->vtable = &classAnimalVFtable; // constructor of ClassAnimal initializes virtual table
	animal1->vtable = &classCatVFtable; // constructor of ClassCat reinitializes virtual table

	animal1->vtable->DoSound(); // call virtual method DoSound()

	animal1->vtable->Destructor(); // call virtual destructor of ClassCat
	animal1->vtable = &classAnimalVFtable; // now virtual table set to ClassAnimal's table again
	animal1->vtable->Destructor(); // call virtual destructor of ClassAnimal

	free(animal1); // release memory

	//-----------------------------------------------

	// code in c++:
	//
	// ClassAnimal* animal = new ClassFrog();
	// animal->DoSound();
	// delete animal;
	//
	// implementation of this code in c:

	ClassAnimal* animal2 = malloc(sizeof(ClassFrog)); // allocate memory for ClassFrog
	animal2->vtable = &classAnimalVFtable; // constructor of ClassAnimal initializes virtual table
	animal2->vtable = &classFrogVFtable; // constructor of ClassFrog reinitializes virtual table

	animal2->vtable->DoSound(); // call virtual method DoSound()

	animal2->vtable->Destructor(); // call virtual destructor of ClassFrog
	animal2->vtable = &classAnimalVFtable; // now virtual table set to ClassAnimal's table again
	animal2->vtable->Destructor(); // call virtual destructor of ClassAnimal

	free(animal2); // release memory

	//-----------------------------------------------

	// code in c++:
	//
	// ClassAnimal* animal = new ClassAnimal();
	// animal->DoSound();
	// delete animal;
	//
	// implementation of this code in c:

	ClassAnimal* animal3 = malloc(sizeof(ClassAnimal)); // allocate memory for ClassAnimal
	animal3->vtable = &classAnimalVFtable; // constructor of ClassAnimal initializes virtual table

	//animal3->vtable->DoSound(); // be careful! pure virtual method call!!!

	animal3->vtable->Destructor(); // call virtual destructor of ClassAnimal

	free(animal3); // release memory


	return EXIT_SUCCESS;
}
