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
	std::cout << "First Name: " << this->firstName << std::endl;
	std::cout << "Last Name: " << this->lastName << std::endl;
	std::cout << "Age: " << this->age << std::endl;
	std::cout << "Courses: " << std::endl;
	for(std::string str : this->classNames)
	{
		std::cout << "\t" << str << std::endl;
	}
}

int Person::getAge()
{
	return this->age;
}
