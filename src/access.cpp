#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <ctime>
#include <cstdlib>

#include <parse.h>

CliParser getInput(int argc, char *argv[], bool isPrint);
void addAccount(std::string first, std::string last, float amount);

int main(int argc, char *argv[])
// Command line args include:
// -i : Input file path
// -o : Output file path
{
	// Parse CLI arguments
	CliParser Parser = getInput(argc, argv, false);

	std::string action =  Parser.getArg("-a");
	if (action == "add"){
		std::string first = Parser.getArg("--first");
		std::string last = Parser.getArg("--last");
		std::string amount = Parser.getArg("--amount");

		if (first.empty()) { std::cerr << "--first required" << std::endl; }
		if (last.empty()){ std::cerr << "--last required" << std::endl; }
		if (amount.empty()){ std::cerr << "--amount required" << std::endl; }

		addAccount(first, last, std::stof(amount));
	}
	else if (action == "rmv"){
		std::cout << "Must remove account #" << Parser.getArg("--id") << std::endl;
	}
	else if (action == "upd"){
		std::cout << "Must update account #" << Parser.getArg("--id") << " with $" << Parser.getArg("--amount") << std::endl;
	}
	else{
		std::cout << "Invalid action " << action << ". Must use one of the following:" << std::endl;
		std::cout << "add: Add a person; REQUIRES --first, --last; OPTIONAL --amount" << std::endl;
		std::cout << "rmv: Remove a person; REQUIRES --id" << std::endl;
		std::cout << "upd: Update a person's account. REQUIRES --id, --amount" << std::endl;
	}

	/*
	// Read in CSV
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
	*/
	return 0;
}

CliParser getInput(int argc, char *argv[], bool isPrint){
	/* Parse inputs to application

	argc : number of input command line args
	argv : command line args as char arrays. Can be any of:
		-a : Action to take. Can be:
			add: Add a person; REQUIRES --first, --last; OPTIONAL --amount
			rmv: Remove a person; REQUIRES --id
			upd: Update a person's account. REQUIRES --id, --amount
		--first : first name
		--last : last name
		--amount : dollar amount change from previous balance. If adding person,
				   this is initial balance.

	isPrint : whether to print out command line args (debug)
	*/
	CliParser Parser;

	// Possible actions
	Parser.configureArg("-a");  // add person

	// Additional args
	Parser.configureArg("--first", "");  // first name; needed for -a
	Parser.configureArg("--last", "");  // last name; needed for -a
	Parser.configureArg("--amount", "");  // dollar amount change; needed for -a, -u
	Parser.configureArg("--id", "");  // 4-digit ID number, needed for -u, -r

	// Parse
	Parser.parseArgs(argc, argv);

	if (isPrint){
		Parser.printArgs();
	}

	return Parser;
}

void addAccount(std::string first, std::string last, float amount){
	/* Add new account
	first : First name
	last : Last name
	amount : Initial investment
	*/
	unsigned randSeed = time(NULL);
		srand(randSeed);
	int id = rand();

	// TODO-Write to file

	std::cout << "Added " << first << " " << last << " with $" << amount << " and Account #" << id << std::endl;
}
