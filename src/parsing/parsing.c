#include "microshell.h"

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return(i);
	
}

void copy_str(t_list *node, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		node->string[i] = str[i];
		i++;
	}
}


void *allocate_strspace(t_list *node, char *str)
{
	int str_size;
	
	str_size = ft_strlen(str);
	node->string = malloc(sizeof(char) * str_size + 1);
	if(!node->string)
		return(NULL);
	copy_str(node, str);
}


t_list *add_node(char *str)
{
	t_list *node;

	if(!str)
		return(NULL);

	node = malloc(sizeof(t_list));
	if(!node)
		return(NULL);
	
	if(!allocate_strspace(node, str))
	{
		free(node);
		return(NULL);
	}

	node->next = NULL;
}


t_list *add_node_to_list(t_list **head, char *str)
{
    t_list *new_node;
    t_list *current;


	new_node = add_node(str);
    if (!new_node)
        return NULL;

    if (!(*head))
    {
        *head = new_node;
    }
    else
    {
        current = *head;
        while (current->next)
        {
            current = current->next;
        }
        current->next = new_node;
    }
    
    return new_node;
}


int start_parse(int argc, char **argv)
{
    t_list *head;
    int i = 0;

    head = NULL;

    while (i < argc)
    {
        add_node_to_list(&head, argv[i]);
	    //free list and quit if error

        i++;
    }


}
