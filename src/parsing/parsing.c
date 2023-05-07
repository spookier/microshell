#include "microshell.h"


int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return(i);
	
}


void copy_str_node(t_list *node, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		node->string[i] = str[i];
		i++;
	}
}



int allocate_strspace(t_list *node, char *str)
{
    int str_size;

    str_size = ft_strlen(str);
    node->string = malloc(sizeof(char) * str_size + 1);
    if (!node->string)
        return (1);
    copy_str_node(node, str);
    return (0);
}


t_list *alloc_node(char *str)
{
	t_list *node;

	if(!str)
		return(NULL);

	node = malloc(sizeof(t_list));
	if(!node)
		return(NULL);
	
	if(allocate_strspace(node, str) == 1)
	{
		free(node);
		return(NULL);
	}

	node->next = NULL;
	return(node);
}


void print_list(t_list *node)
{
	t_list *tmp;

	tmp = node;
	while (tmp != NULL)
	{
		printf("%s ", tmp->string);
		tmp = tmp->next;
	}
	printf("\n");
}


int start_parse(t_list **list, int argc, char **argv)
{
	t_list *new_node;
	t_list *current;

	new_node = NULL;
    int i = 0;
    while (i < argc)
    {
		new_node = alloc_node(argv[i]);
		if(!new_node)
		{
			//free list then quit
			return(1);
		}
		if(*list == NULL)
			*list = new_node;
		else
		{
			current = *list;
			while (current->next != NULL)
				current = current->next;
			current->next = new_node;
		}
        i++;
    }
	//print_list(*list);
	return(0);
}