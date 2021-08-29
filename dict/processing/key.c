#include "../../constants.h"

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

int	calculate_hash(char *str, int *i)
{
	int	result;
    int index;

    index = 0;
	result = 0;
	while (is_digit(str[*i + index]))
	{
		result = (str[*i + index] * (*i + 1) + result) % g_max;
		(*i)++;
	}
	return (result);
}

int	set_key(char *str, int *index, char **key)
{
	int	result;
	int	i;
	int	j;

	i = 0;
	result = calculate_hash(str, &i, *index);
	*key = malloc(i * sizeof (char) + 1);
	j = 0;
	while (j < i)
	{
		(*key)[j] = str[j + *index];
		j++;
	}
	(*key)[j] = '\0';
	*index += i;
	return (result);
}
