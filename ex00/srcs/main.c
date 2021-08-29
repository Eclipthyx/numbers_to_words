#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/read.h"
#include "../include/rec.h"
#include "../include/help_functions.h"
#include "../include/constants.h"
#include "../include/free_memory.h"

char	*remove_zeroes(char *o)
{
	int	i;

	i = 0;
	while (o[i] == '0')
	{
		i++;
	}
	if (o[i] == '\0')
		return (o + i - 1);
	return (o + i);
}

void	f(char *string, int start, struct s_node **dict)
{
	string = remove_zeroes(string + start);
	rec(string, count_digits(string), dict, 0);
	write(1, "\n", 1);
	free_hash_map(dict);
}

int	f2(int start)
{
	if (start == -1)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	struct s_node	**dict;
	char			*string;
	int				start;

	if (argc == 2)
		string = argv[1];
	else if (argc == 3)
		string = argv[2];
	else
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (fill_dict(argc, argv, &dict))
	{
		write(1, "Dict Error\n", 11);
		return (1);
	}
	start = check_string(string);
	if (f2(start))
		return (1);
	f(string, start, dict);
	return (0);
}
