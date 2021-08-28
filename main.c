#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
//Key pair entries for use in the hashmap linked list dictionary
struct Entry{
	struct	Entry *next;
	char	*key;
	char	*value;
};

int main(int argc, char **argv)
{
	int			fd;
	char		*c;
	int	const	BUFFER_SIZE = 1000;

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
	c = malloc(BUFFER_SIZE * sizeof (char));
	//Read the file pointed to by fd for BUFFER_SIZE characters long and put it into 
	//the char * c
	read(fd, c, BUFFER_SIZE);

	//Output result so we can see
	write(1, c, BUFFER_SIZE);
	
	//Index in table pointed to by fd (like pointing to numbers.dict)  
	printf("%d", fd);

}