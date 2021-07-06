#include <iostream>

#include <io.h>

// === PERSON CLASS ===
Person::Person(int age, std::string firstName, std::string lastName, std::vector<std::string> classNames)
{
	this->age = age;
	this->firstName = firstName;
	this->lastName = lastName;
	this->classNames = classNames;
}

void Person::printInfo()
{
	std::cout << "First Name: " << this->firstName;
	std::cout << "   Last Name: " << this->lastName;
	std::cout << "   Age: " << this->age;
	std::cout << "   Courses: ";
	for(std::string str : this->classNames)
	{
		std::cout << "   " << str;
	}
	std::cout << std::endl;
}

int Person::getAge()
{
	return this->age;
}
