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
		if (temp == "-f")
		{
			filename = std::string(argv[i + 1]);
			std::cout << "Filename: " << filename << std::endl;
		}
	}

	// Read file line by line
	std::ifstream infile(filename);
	std::string str;
	
	// Temp Vars
	int age;
	std::string firstName;
	std::string lastName;
	std::vector<std::string> classNames;

	while (std::getline(infile, str))
	{
		// Split at the commas, remove spaces
		str.erase(std::remove(str.begin(), str.end(), ' '), str.end()); // remove spaces
		std::vector<std::string> parsed = split(str, ',');

		age = std::stoi(parsed[2]);
		firstName = parsed[0];
		lastName = parsed[1];
		std::vector<std::string> classNames;
		for (int i = 3; i < parsed.size(); i++)
			classNames.push_back(parsed[i]);

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
