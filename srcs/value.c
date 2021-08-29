#include "../include/dict.h"
#include <stdlib.h>

int	is_alpha(char c)
{
	if ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z')
		|| (c == '-'))
	{
		return (1);
	}
	return (0);
}

void	set_value(char *str, int *index, struct s_node *node)
{
	int	i;
	int	j;

	i = 0;
	while (str[i + *index] != '\n' && str[i + *index] != '\0')
	{
		i++;
	}
	node->value = malloc(i * sizeof (char) + 1);
	j = 0;
	while (j < i)
	{
		node->value[j] = str[j + *index];
		j++;
	}
	node->value[j] = '\0';
	*index += i;
}
