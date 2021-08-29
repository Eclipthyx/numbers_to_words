#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/dict.h"
#include "../include/help_functions.h"
#include "../include/dict_processing.h"
#include "../include/constants.h"
#include "../include/rec.h"

void	fill_dict(int argc, char **argv, struct s_node ***dict)
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
		write(1, "Error\n", 6);
	file_string = malloc(g_buffer_size * sizeof (char));
	file_size = read(fd, file_string, g_buffer_size);
	i = 0;
	*dict = malloc(g_max * sizeof (struct s_node *));
	init_dict(*dict);
	while (i < file_size)
	{		
		if (is_digit(file_string[i]) && (i < file_size))
		{
			process_line(file_string, &i, *dict);
		}
		i++;
	}
}
