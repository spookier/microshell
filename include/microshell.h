#ifndef MICROSHELL_H
# define MICROSHELL_H

#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "string.h"
#include <sys/wait.h>

typedef struct s_list t_list;

typedef struct s_list
{
	char *string;
	t_list *next;

} t_list;


int exec(int argc, char **argv, char **env);
int start_parse(int argc, char **argv);

#endif