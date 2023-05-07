#ifndef PARSING_H
# define PARSING_H

typedef struct s_list t_list;

typedef struct s_list
{
	char *string;
	t_list *next;

} t_list;


int		start_parse(t_list **list, int argc, char **argv);
int 	ft_strlen(char *str);

#endif