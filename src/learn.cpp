#include <iostream>
#include <string>
#include <map>
#include <fstream>

#include <parse.h>

int main(int argc, char *argv[])
// Command line args include:
// -i : Input file path
// -o : Output file path
{
	// Parse CLI arguments
	CliParser Parser;
	Parser.configureArg("-i"); // no default input
	Parser.configureArg("-o", "output.txt"); // default for output
	Parser.parseArgs(argc, argv);
	// Parser.printArgs();

	// Parse CSV File for input features and target values
	std::string line;
	std::ifstream inFile(Parser.getArg("-i"));
	if (inFile.is_open()) {
		while (std::getline(inFile, line)) {
			std::cout << line << std::endl;
		}
		inFile.close();
	}
	else {
		std::cout << "Unable to open file" << std::endl;
	}

	// Construct graph of nodes

	// Train

	// Output weights to file
	std::ofstream outFile(Parser.getArg("-o"));
  	outFile << "Writing this to a file.\n";
	outFile.close();
	std::cout << "Output written to " << Parser.getArg("-o") << std::endl;

	return 0;
}
