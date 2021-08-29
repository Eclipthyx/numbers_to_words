#ifndef KEY_H
# define KEY_H
# include "dict.h"

int	is_digit(char c);
int	calculate_hash(char *str, int *i);
int	set_key(char *str, int *index, struct s_node *node);
#endif