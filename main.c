#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "file.c"
#include "constants.h"


int		main(int argc, char **argv)
{
    struct      s_node **dict;
    char		*string;
	
	fill_dict(argc, argv, &dict);
	
	if (argc == 2)
		string = argv[1];
	else if (argc == 3)
		string = argv[2];
	else
		write(1, "Error\n", 6);
	rec(string, count_digits(string), dict);
}
