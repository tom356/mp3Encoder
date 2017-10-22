#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#include "InputParser.h"

void runLame(const std::string &input, const std::string &output)
{
	pid_t  pid = fork();
	switch(pid)
	{
		case -1: 
			std::cout << "fork Error" << std::endl; 
		break;
			
		case 0 : // child process
			execl("/usr/bin/lame", "/usr/bin/lame", input.c_str(), output.c_str(), (char *) 0);
		break;
			
		default:	// parent process
			wait(0);	// wait for child to finish
		break;
	}
}
int main(int argc, char**argv )
{
	LameWrapper::Params p;
	if(LameWrapper::parseInput(argc, argv, p) == 0)
		runLame(p.input, p.output);
	else
		std::cout << "parsing failed" << std::endl;
	return 0;
}
