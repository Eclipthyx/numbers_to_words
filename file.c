#include "dict.c"
static	int	const	BUFFER_SIZE = 10000000;
extern	int	const	max;


int	is_digit(char c)
{
	if(c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

int is_alpha(char c)
{
	if((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z')
		|| (c == '-'))
	{
		return (1);
	}
	return (0);
}

int	is_whitespace(char c)
{
	if((c == '\t') || c == '\v' || c == '\r'
		|| c == '\n' || c == ' ' || c == ':')
	{
		return (1);
	}
	return (0);
}

int	hash(char *str, int index, char **key)
{
	int	result;
	int	i;
	int j;

	i = 0;
	result = 0;
	while (is_digit(str[i + index]))
	{
		result = (str[i + index] * (i + 1) + result) % max;
		i++;
	}
	*key = malloc(i);
	j = 0;
	while (j < i)
	{
		(*key)[j] = str[index + j];
	}

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
		fd = open("numbers.dict", O_RDONLY);
	}else if(argc == 3)
	{
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
	write(1, file_string, BUFFER_SIZE);
	printf("\n\n%d, %d\n", fd, file_size);
	
	int		i = 0;
	struct	s_node* new_node;
	int		index_hash;
	char	**key;
	char	**value;
	int		key_size;
	int		value_size;

	while(i < file_size)
	{
		while(is_digit((file_string[i]) && i < file_size))
		{
			index_hash = hash(file_string, i, key);
			i++;
		}
		while(is_whitespace((file_string[i]) && i < file_size))
			i++;
		while(is_alpha((file_string[i]) && i < file_size))
		{
			i++;
		}
		while(is_whitespace((file_string[i]) && i < file_size))
			i++;
	}
}
