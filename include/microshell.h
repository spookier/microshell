#ifndef MICROSHELL_H
# define MICROSHELL_H

#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "string.h"
#include <sys/wait.h>

#include "../include/parsing.h"
#include "../include/exec.h"


int exec(int argc, char **argv, char **env);
int start_parse(int argc, char **argv);

#endif