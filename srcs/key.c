#include "../include/constants.h"
#include "../include/help_functions.h"
#include "../include/dict.h"
#include <stdlib.h>

int	calculate_hash(char *str, int *i)
{
	int	result;
	int	index;

	index = 0;
	result = 0;
	while (is_digit(str[*i + index]))
	{
		result = (str[*i + index] * (*i + 1) + result) % g_max;
		(*i)++;
	}
	return (result);
}

int	set_key(char *str, int *index, struct s_node *node)
{
	int	result;
	int	i;
	int	j;

	i = 0;
	result = calculate_hash(str +*index, &i);
	node->key = malloc(i * sizeof (char) + 1);
	node->next = 0;
	j = 0;
	while (j < i)
	{
		node->key[j] = str[j + *index];
		j++;
	}
	node->key[j] = '\0';
	*index += i;
	return (result);
}
