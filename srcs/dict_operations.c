#include "../include/help_functions.h"
#include "../include/dict.h"

char	*find(struct s_node *node, char *key)
{
	struct s_node	*ptr;

	ptr = node;
	while (ptr != 0)
	{
		if (str_cmp(ptr->key, key) == 0)
		{
			return (ptr->value);
		}
		ptr = ptr->next;
	}
	return (0);
}

void	insert(struct s_node **dict, struct s_node *new_node, int index)
{
	struct s_node	*ptr;

	if (dict[index] != 0)
	{
		ptr = dict[index];
		while (ptr->next != 0)
		{
			ptr = ptr->next;
		}
		ptr->next = new_node;
	}
	else
	{
		dict[index] = new_node;
	}
}
