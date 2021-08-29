#include "key.h"
#include "value.h"
#include "whitespace.h"
#include "../dict_operations.h"

//Returns hash that serves as an index for a dict
//And sets key and value
void	process_line(char *str, int *index, struct s_node *new_node, struct s_node **dict)
{
	int		index_hash;
	char	**new_key;
	char	**new_value;

	new_node->next = 0;
	new_node->key = *new_key;
	new_node->value = *new_value;
	index_hash = set_key(str, index, &new_node->key);
	skip_whitespace(str, index);
	set_value(str, index, &new_node->value);
	insert(dict, new_node, index_hash);
}
