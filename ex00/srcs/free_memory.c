#include "../include/constants.h"
#include "../include/dict.h"
#include <stdlib.h>

void	free_hash_map(struct s_node **dict)
{
	int				i;
	struct s_node	*ptr;
	struct s_node	*ptr2;

	i = 0;
	while (i < g_max)
	{
		if (dict[i] != 0)
		{
			ptr = dict[i];
			while(ptr->next != 0)
			{
				ptr2 = ptr->next;
				free(ptr->key);
				free(ptr->value);
				free(ptr);
				ptr = ptr2;
			}
			free(ptr->key);
			free(ptr->value);
			free(ptr);
		}
		i++;
	}
	free(dict);
}
