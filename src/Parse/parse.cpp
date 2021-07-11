#include <iostream>
#include <string>
#include <map>

#include "parse.h"

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
	// Loop through CLIs
	for (int i = 0; i < argc; i++){
		if (i == 0){
			continue;
		} // first arg is not important (file name)

		// Ensure CLI is a valid configured flag
		bool isValid = false;
		std::string argument = std::string(argv[i]); // cast char* to std::string

		for (std::pair<std::string, std::string> keyValPair : this->cliArgs) {
			// Accessing KEY from element
			if (argument == keyValPair.first){
				// Check if it matches any. Assume the following input matches this flag!
				this->cliArgs[argument] = std::string(argv[i+1]);
				isValid = true;
				i++;
				break;
			}
		}

		if (!isValid){
			std::cout << "Unknown flag " << argument << ". Ignoring" << std::endl;
		}
	}

	// Ensure no configured parameters are left as empty string
	/*
	for (std::pair<std::string, std::string> cliArg : this->cliArgs) {
		if (cliArg.second.empty()){
			std::cerr << "CLI Argument " << cliArg.first << " is required" << std::endl;
		}
	}
	*/
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
