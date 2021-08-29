#include "../include/key.h"
#include "../include/value.h"
#include "../include/whitespace.h"
#include "../include/dict_operations.h"
#include <stdlib.h>

//Returns hash that serves as an index for a dict
//And sets key and value
void	process_line(char *str, int *index, struct s_node **dict)
{
	int				index_hash;
	struct s_node	*new_node;

	new_node = malloc(sizeof (struct s_node));
	index_hash = set_key(str, index, new_node);
	skip_whitespace(str, index);
	set_value(str, index, new_node);
	insert(dict, new_node, index_hash);
}
