#include <iostream>
#include <string>
#include <map>

#include "parse.h"

void CliParser::setArg(std::string inFlag, std::string argument){
	// Set the value of a command line argument
	this->cliArgs[inFlag] = argument;
}

void CliParser::configureArg(std::string inFlag){
	// Add an expected CLI argument flag
	this->cliArgs[inFlag] = "";
}

void CliParser::configureArg(std::string inFlag, std::string defaultArg){
	// Add an expected CLI argument flag with default value
	this->cliArgs[inFlag] = defaultArg;
}

// PARSING OF ARGUMENTS
void CliParser::parseArgs(int argc, char *argv[]){
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
void CliParser::printArgs(){
	// Print all argument key/value pairs
	std::cout << "CliParser Key-Values: " << std::endl;

	for (std::pair<std::string, std::string> element : this->cliArgs) {
		std::cout << element.first << " : " << element.second << std::endl;
	}
}

std::string CliParser::getArg(std::string inFlag){
	// Return value of a parsed CLI argument
	return this->cliArgs[inFlag];
}

/*
class CliParser {
	private:
   		std::map<std::string, std::string> cliArgs;

		void 

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
*/