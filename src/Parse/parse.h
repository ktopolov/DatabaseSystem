#include <string>
#include <map>

class CliParser {
	private:
   		std::map<std::string, std::string> cliArgs;
		void setArg(std::string inFlag, std::string argument);

	public:
		void configureArg(std::string inFlag);
		void configureArg(std::string inFlag, std::string defaultArg);
		void parseArgs(int argc, char *argv[]);
		void printArgs();
		std::string getArg(std::string inFlag);
};
