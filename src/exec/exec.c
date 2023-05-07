#include "microshell.h"

// we use child to not lose main flow of parent because of execve
// built-in = function doesnt use execve

//alloc enough space for arg of cd and pass it

char *ft_strcpy(char *dest, const char *src) 
{
    if (!src || !dest)
        return (NULL);
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
    return (dest);
}


char **execve_arg_convert(char* str)
{
	char **execve_arg;
	int size;

	execve_arg = calloc(2, sizeof(char *));
	if(!execve_arg)
		return(NULL);
	size = ft_strlen(str);
	execve_arg[0] = malloc((size + 1) * sizeof(char));
	//execve_arg[0][0] = ' ';
	execve_arg[0] = ft_strcpy(execve_arg[0], str);
	execve_arg[0][size] = '\0';
	execve_arg[1] = NULL;
	
    return (execve_arg);
}


int exec(t_list **list, int argc, char **argv, char **env)
{	
	t_list *current;
	char **execve_arg;

	int pid;

	current = *list;
	if(!*list)
		return(1);

	while (current != NULL)
	{
		if(strcmp(current->string, "cd") == 0)
		{
			//pid = fork();
			//execve("/bin/echo", argv, env);
			if ((current != NULL && current->next == NULL)
				|| (current != NULL && current->next != NULL && current->next->next != NULL))
			{
				write(2, "error: cd: bad arguments\n", ft_strlen("error: cd: bad arguments\n"));
				return(1);
			}
			if(current != NULL && current->next != NULL);
			{
				if (chdir(current->next->string) == -1)
				{
					write(2, "error: cd: cannot change directory to ", ft_strlen("error: cd: cannot change directory to "));
					write(2, current->next->string, ft_strlen(current->next->string));
					write(2, "\n", 1);
					return(1);
				}
				system("ls");
			}
		}
		current = current->next;
	}
	return(0);
}
