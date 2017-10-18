#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include "InputParser.h"
void runLame(const std::string &input, const std::string &output)
{
	execl("/usr/bin/lame", "/usr/bin/lame", input.c_str(), output.c_str(), (char *) 0);
	//execl("/bin/ls", "/bin/ls", "-l", (char *) 0);
}
int main(int argc, char**argv )
{
	WawToMP3::Params p;
	if(WawToMP3::parseInput(argc, argv, p) == 0)
	{
		std::cout  << p.input << std::endl;
		std::cout  << p.output << std::endl;
		runLame(p.input, p.output);
	}
	else
	{
		std::cout << "parsing failed" << std::endl;
	}	
	return 0;
}