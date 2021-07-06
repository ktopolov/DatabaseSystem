// This is a sample Hello World program to be built
//
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

#include <io.h>

// PROTOTYPES
std::vector<std::string> split(std::string str, char delimiter);

// MAIN
int main(int argc, char** argv)
// argv : Pairs of
// -f : <FILENAME.txt>
{
	// Parse input args
	std::cout << "You have entered " << argc << " arguments:" << std::endl;
	std::string filename;
	std::string temp;
	for (int i = 0; i < argc; ++i)
	{
		temp = std::string(argv[i]);
		std::cout << temp << std::endl;
		if (temp == "-f")
		{
			filename = std::string(argv[i + 1]);
			std::cout << "Filename: " << filename << std::endl;
		}
	}

	// Temporary variables
	int age;
	std::string firstName;
	std::string lastName ;
	std::vector<std::string> classNames;

	// Read file line by line
	std::ifstream infile(filename);
	std::string str;
	while (std::getline(infile, str))
	{
		// Split at the commas, remove spaces
		str.erase(std::remove(str.begin(), str.end(), ' '), str.end()); // remove spaces
		std::vector<std::string> parsed = split(str, ',');

		firstName = parsed[0];
		lastName = parsed[1];
		age = stoi(parsed[2]);
		classNames = std::vector<std::string> {"ECE580", "ECE591"};

		Person NewPerson(age, firstName, lastName, classNames);
		NewPerson.printInfo();
	}
	
	return 0;
}

std::vector<std::string> split(std::string str, char delimiter)
{
	std::vector<std::string> result;
	std::stringstream s_stream(str); //create string stream from the string

	while(s_stream.good())
	{
		std::string substr;
		std::getline(s_stream, substr, delimiter); //get first string delimited by comma
		result.push_back(substr);
	}
	return result;
}
