#include "dict.c"
#include "dict/dict.h"

static	int	const	BUFFER_SIZE = 10000000;
extern	int	const	max;


//Returns hash that serves as an index for a dict
//And sets key and value
int	index_hash(char *str, int *index, struct s_node *node)
{
	int	result;

	result = set_key(str, index, &node->key);
	skip_whitespace(str, index);
	set_value(str, index, &node->value);

	return (result);
}


void fill_dict(int argc, char **argv, struct s_node **dict)
{
	int			fd;
	char		*file_string;
	//Check if there are 2 or three arguments else error.
	//Program name, string argument, optional(string argument)

	//Then open file with open(FILENAME, MODE). 
	//MODE can be read, write, readwrite etc. But we want only read 
	//open returns a positive integer 3 to infinity if file can be opened
	// and 0 if file cannot be opened.

	//The integer is the index in a table which links the index to a particular file
	//The integer always starts at 3 and goes up. 
	//When a file is closed again with close(fd) the index in the table will be free again
	//and some other file can use that index.
	if(argc == 2)
	{
		write(1, "FIRST\n", 6);
		fd = open("numbers.dict", O_RDONLY);
	}else if(argc == 3)
	{
		write(1, "SECOND\n", 7);
		fd = open(argv[1], O_RDONLY);
	}else
	{
		write(1, "Error\n", 6);
	}
	
	//Allocate a buffer (memory region) so we can write all the file data  we read somewhere
	file_string = malloc(BUFFER_SIZE * sizeof (char));
	//Read the file pointed to by fd for BUFFER_SIZE characters long and put it into 
	//the char * file_string
	int file_size = read(fd, file_string, BUFFER_SIZE);

	//Output result so we can see
	//write(1, file_string, BUFFER_SIZE);
	//printf("\n\n%d, %d\n", fd, file_size);
	
	int		i = 0;
	struct	s_node* new_node;
	int		index_dict;
	char	**new_key;
	char	**new_value;


	while(i < file_size)
	{		
		if(is_digit(file_string[i]) && (i < file_size))
		{
			new_node = malloc(sizeof (struct s_node));
			new_node->next = 0;
			new_node->key = *new_key;
			new_node->value = *new_value;
			index_dict = index_hash(file_string, &i, new_node);
			printf("%s, %s\n\n", new_node->key, new_node->value);

		}
		i++;
	}
	
}
