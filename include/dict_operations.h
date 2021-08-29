#ifndef DICT_OPERATIONS_H
# define DICT_OPERATIONS_H

char	*find(struct s_node *node, char *key);
void	insert(struct s_node **dict, struct s_node *new_node, int index);
#endif