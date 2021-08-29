#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/dict.h"
#include "../include/help_functions.h"
#include "../include/dict_processing.h"
#include "../include/constants.h"
#include "../include/rec.h"
#include "../include/whitespace.h"
#include "../include/key.h"

struct	s_node	**init_dict(void)
{
	int				i;
	struct s_node	**dict;

	dict = malloc(g_max * sizeof (struct s_node *));
	i = 0;
	while (i < g_max)
	{
		dict[i] = 0;
		i++;
	}
	return (dict);
}

int	fill_dict(int argc, char **argv, struct s_node ***dict)
{
	int				fd;
	char			*file_string;
	int				file_size;
	int				i;

	if (argc == 2)
		fd = open("numbers.dict", O_RDONLY);
	else if (argc == 3)
		fd = open(argv[1], O_RDONLY);
	else
		return (1);
	file_string = malloc(g_buffer_size * sizeof (char));
	file_size = read(fd, file_string, g_buffer_size);
	i = 0;
	*dict = init_dict();
	while (i < file_size)
	{		
		if (is_digit(file_string[i]) && (i < file_size))
			process_line(file_string, &i, *dict);
		i++;
	}
    free(file_string);
	return (0);
}

int	check_string(char *str)
{
	int	i;
	int	s;
	int	index;
	int	flag;

	flag = 0;
	i = 0;
	s = 1;
	if (str[i] != '\0')
	{
		while (is_whitespace(str[i]))
			i++;
		while (str[i] == '+' || str[i] == '-')
		{
			if (str[i++] == '-')
				s *= -1;
		}
		index = i;
		while (is_digit(str[i]) && flag++)
			i++;
		if (s == -1 || flag == 0)
			return (-1);
		return (index);
	}
	return (-1);
}
