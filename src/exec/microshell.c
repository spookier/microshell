#include "../include/microshell.h"

int main(int argc, char **argv, char **env)
{
	t_list *list;

    list = NULL;
	if (start_parse(&list, argc, argv) == 1)
	{
		printf("Error parsing\n");
		return(1);
	}
	if (exec(&list, argc, argv, env) == 1)
	{
		printf("Error exec\n");
		return(1);
	}

	
	//free parsing
}