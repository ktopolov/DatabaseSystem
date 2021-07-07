#include <iostream>
#include <string>
#include <map>



class CliParser {
	private:
   		std::map<std::string, std::string> cliArgs;

		void setArg(std::string inFlag, std::string argument){
			// Set the value of a command line argument
			this->cliArgs[inFlag] = argument;
		}

	public:
		// CONFIGURATION OF ARGUMENTS
		void configureArg(std::string inFlag){
			// Add an expected CLI argument flag
			this->cliArgs[inFlag] = "";
		}
		void configureArg(std::string inFlag, std::string defaultArg){
			// Add an expected CLI argument flag with default value
			this->cliArgs[inFlag] = defaultArg;
		}

		// PARSING OF ARGUMENTS
		void parseArgs(int argc, char *argv[]){
			// Parse input CLI arguments
			if (argc > 1) {
				for (int i = 1; i < argc; i++){ // for each CLI flag
					bool isFound = false;
					std::string argument = std::string(argv[i]); // cast char* to std::string

					for (std::pair<std::string, std::string> keyValPair : this->cliArgs) {
						// Accessing KEY from element
						if (argument == keyValPair.first){
							// Check if it matches any. Assume the following input matches this flag!
							this->cliArgs[argument] = std::string(argv[i+1]);
							isFound = true;
							i++;
							break;
						}
					}

					if (!isFound){
						std::cout << "Unknown flag " << argument << ". Ignoring" << std::endl;
					}
				}
			}

			// Verify all arguments have been filled
			for (std::pair<std::string, std::string> keyValPair : this->cliArgs) {
				if (keyValPair.second.empty()) {
					std::cout << "Flag " << keyValPair.first << " required" << std::endl;
				}
			}
		}

		// PRINT CONFIGURED ARGUMENTS
		void printArgs(){
			// Print all argument key/value pairs
			std::cout << "CliParser Key-Values: " << std::endl;

			for (std::pair<std::string, std::string> element : this->cliArgs) {
				std::cout << element.first << " : " << element.second << std::endl;
			}
		}

		std::string getArg(std::string inFlag){
			// Return value of a parsed CLI argument
			return this->cliArgs[inFlag];
		}
};

int main(int argc, char *argv[])
// Command line args include:
// -i : Input file path
// -o : Output file path
{
	CliParser Parser;
	Parser.configureArg("-i"); // no default input
	Parser.configureArg("-o", "output.txt"); // default for output
	Parser.parseArgs(argc, argv);
	Parser.printArgs();
	
	//

	/*
	// Use map to hold command line args
	std::map<std::string, std::string> cliArgs = {
		{"inputFile", ""},
		{"outputFile", ""}
	};

	std::cout << "This is a placeholder for learn.cpp" << std::endl;

	for (int i = 0; i < argc; i++)
	{
		std::string argument = std::string(argv[i]);
		if (argument == "-i"){
			cliArgs["inputFile"] = std::string(argv[i + 1]);
			i += 1; // skip this next arg
		}
		else if (argument == "-o"){
			cliArgs["outputFile"] = std::string(argv[i + 1]);
			i += 1; // skip this next arg
		}
		else if (i > 0){
			std::cout << "Unknown CLI Argument " << argument << std::endl;
		}
	}

	if (cliArgs["inputFile"].empty()) {return 1;}
	if (cliArgs["outputFile"].empty()) {return 1;}

	std::cout << "Input file: " << cliArgs["inputFile"] << std::endl;
	std::cout << "Output File: " << cliArgs["outputFile"] << std::endl;
	*/
	return 0;
}

