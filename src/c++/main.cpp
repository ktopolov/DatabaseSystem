// This is a sample Hello World program to be built
//
#include <iostream>
#include <io.h>

int main(int argc, char** argv)
{
	std::cout << "You have entered " << argc << " arguments:" << std::endl;
	for (int i = 0; i < argc; ++i)
	{
        	std::cout << argv[i] << std::endl;
	}

	std::cout << "Addition is " << add(1, 2) << std::endl; 
    	return 0;
}
