#include "dict/dict.h"
#include "help_functions/help_functions.h"
#include "dict/processing/dict_processing.h"
#include "constants.h"
#include "rec.h"

void	fill_dict(int argc, char **argv, struct s_node ***dict)
{
	int		fd;
	char	*file_string;
	int		file_size;
	int		i;

	if (argc == 2)
		fd = open("numbers.dict", O_RDONLY);
	else if (argc == 3)
		fd = open(argv[1], O_RDONLY);
	else
		write(1, "Error\n", 6);
	file_string = malloc(BUFFER_SIZE * sizeof (char));
	file_size = read(fd, file_string, BUFFER_SIZE);
	i = 0;
	*dict = malloc(g_max * sizeof (struct s_node *));
	init_dict(*dict);
	while (i < file_size)
	{		
		if (is_digit(file_string[i]) && (i < file_size))
		{
			struct s_node *new_node;
			new_node = malloc(sizeof (struct s_node));
			process_line(file_string, &i, new_node, *dict);
		}
		i++;
	}
}
