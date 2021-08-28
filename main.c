#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
struct Entry{
	struct	Entry *next;
	char	*key;
	char	*value;
};

int main(int argc, char **argv)
{
	int		fd;
	char	*c;

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

	int i = 0;
	c = malloc(1000 * sizeof (char));
	read(fd, c, 1000);

		write(1, c, 1000);
	

	printf("%d", fd);

}