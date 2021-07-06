#include <vector>
#include <string>

class Person
{
public:
	Person(int age, std::string firstName, std::string lastName, std::vector<std::string> classNames);
	void printInfo();
	int getAge();
	int age;

private:
	std::string firstName;
	std::string lastName;
	std::vector<std::string> classNames;
};
