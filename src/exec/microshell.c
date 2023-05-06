#include "../include/microshell.h"

int main(int argc, char **argv, char **env)
{
	if(!start_parse(argc, argv))
	{
		printf("Error parsing\n");
		return(1);
	}
	if(!exec(argc, argv, env))
	{
		printf("Error exec\n");
		return(1);
	}
}