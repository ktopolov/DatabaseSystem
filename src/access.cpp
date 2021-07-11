#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

#include <parse.h>

CliParser getInput(int argc, char *argv[], bool isPrint);
void addAccount(std::string file, std::string first, std::string last, float amount);

int main(int argc, char *argv[])
/* Run application

argc : number of input command line args
	argv : command line args as char arrays. Can be any of:
		-f : Database CSV filepath
		-a : Action to take. Can be:
			add: Add a person; REQUIRES --first, --last; OPTIONAL --amount
			rmv: Remove a person; REQUIRES --id
			upd: Update a person's account. REQUIRES --id, --amount
		--first : first name
		--last : last name
		--amount : dollar amount change from previous balance. If adding person,
				   this is initial balance.

Example: From top level of repo:
	./build/Access -f ~/projects/database/db.csv -a add --first John --last Jones --amount 20.0
*/
{
	// Parse CLI arguments
	CliParser Parser = getInput(argc, argv, false);
	std::string action = Parser.getArg("-a");
	std::string file =  Parser.getArg("-f");

	if (action == "add"){
		std::string first = Parser.getArg("--first");
		std::string last = Parser.getArg("--last");
		std::string amount = Parser.getArg("--amount");

		if (first.empty()) { std::cerr << "--first required" << std::endl; }
		if (last.empty()){ std::cerr << "--last required" << std::endl; }
		if (amount.empty()){ std::cerr << "--amount required" << std::endl; }

		addAccount(file, first, last, std::stof(amount));
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

	// Read in CSV
	std::string line;
	std::ifstream inFile(Parser.getArg("-f"));
	std::cout << "Attempting to open file " << Parser.getArg("-f") << std::endl;

	if (inFile.is_open()) {
		while (std::getline(inFile, line)) {
			std::cout << line << std::endl;
		}
		inFile.close();
	}
	else {
		std::cout << "Unable to open file" << std::endl;
	}

	return 0;
}

CliParser getInput(int argc, char *argv[], bool isPrint){
	/* Parse inputs to application

	argc : number of input command line args
	argv : command line args as char arrays. Can be any of:
		-f : Filepath to CSV database
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
	Parser.configureArg("-a");
	Parser.configureArg("-f");

	// Additional args
	Parser.configureArg("--first", "");
	Parser.configureArg("--last", "");
	Parser.configureArg("--amount", "");
	Parser.configureArg("--id", "");

	// Parse
	Parser.parseArgs(argc, argv);

	if (isPrint){
		Parser.printArgs();
	}

	return Parser;
}

void addAccount(std::string file, std::string first, std::string last, float amount){
	/* Add new account
	file : database CSV file to add to
	first : First name
	last : Last name
	amount : Initial investment
	*/
	unsigned randSeed = time(NULL);
		srand(randSeed);
	int id = rand() % 10000; // number between 0 and 9999

	// TODO-Write to file
	std::ofstream outFile(file, std::ios::app); // append mode
	outFile << id << ", " << first << ", " << last << ", " << amount;
	outFile.close();
}
