#include "microshell.h"

// we use child to not lose main flow of parent because of execve
// built-in = function doesnt use execve

int exec(int argc, char **argv, char **env)
{	
	int i;
	int pid;
	int status;

	i = 1;
	while (i < argc)
	{
		if(strcmp(argv[i], "echo") == 0)
		{
			printf("-- echo detected\n");
			pid = fork();
			if(pid == 0)
			{
				execve("/usr/bin/echo", &argv[i], env);
				return(1);
			}
		}
		i++;
	}
	printf("-- end of program\n");
}
