#include "microshell.h"

// we use child to not lose main flow of parent because of execve
// built-in = function doesnt use execve

//alloc enough space for arg of cd and pass it
char* const* convert_to_const_char_pointer(char* str)
{
    char* const* const_ptr;
	const ptr = (char* const*)malloc(sizeof(char*));
	strcpy(ptr, str);
    return const_ptr;
}


int exec(t_list **list, int argc, char **argv, char **env)
{	
	t_list *current;
	char* const* arg_const;
	int pid;

	current = *list;
	if(!*list)
		return(1);
	while (current != NULL)
	{
		if(current->string != NULL && current->next != NULL && strcmp(current->string, "cd") == 0)
		{
			pid = fork();
			if(pid == 0)
			{
				arg_const = convert_to_const_char_pointer(current->next->string);
				execve("/usr/bin/echo", arg_const, env);
				return(1);
			}
		}
		current = current->next;
	}
	return(0);
}
