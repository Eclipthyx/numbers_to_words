#include "dict.c"
#include "dict/dict.h"
#include "constants.h"

/*
 *This function finds the given key in the Linked List
 *Returns it's index
 *Returns -1 in case key is not present
*/
int find(struct s_node *list, char *key)
{
	int retval = 0;
	struct s_node *temp = list;
	while (temp != NULL) 
	{
		if (temp->key == key)
		{
			return retval;
		}
  		temp = temp->next;
		retval++;
	}
	return -1;
 
}
 
/* Returns the s_node (Linked List item) located at given find_index  */
struct s_node* get_element(struct s_node *list, int find_index)
{
	int i = 0;
	struct s_node *temp = list;
	while (i != find_index) 
        {
		temp = temp->next;
		i++;
	}
	return temp;
}

void insert(struct s_node **dict, struct s_node *new_node, int index)
{
	struct s_node *ptr; 
	if(dict[index] != 0)
	{
		ptr = dict[index];
		while(ptr->next != 0)
		{
			ptr = ptr->next;
		}
		ptr->next = new_node;
	}else{
		dict[index] = new_node;
	}
}
//Returns hash that serves as an index for a dict
//And sets key and value
void	process_line(char *str, int *index, struct s_node *node, struct s_node **dict)
{
	int	index_hash;

	index_hash = set_key(str, index, &node->key);
	skip_whitespace(str, index);
	set_value(str, index, &node->value);
	insert(dict, node, index_hash);
}




/* To display the contents of Hash Table */
void display(struct s_node **dict)
{
	int	i;
	struct s_node *ptr;

	i = 0;
	while(i < g_max)
	{
		if(dict[i] != 0)
		{
			printf("%s, %s", dict[i]->key, dict[i]->value);
			ptr = dict[i];
			while(ptr->next != 0)
			{
				ptr = ptr->next;
				printf("<---> %s, %s", ptr->key, ptr->value);
			}
			printf("\n");
		}
		i++;
	}
}

void fill_dict(int argc, char **argv, struct s_node ***dict)
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
	int		index;
	char	**new_key;
	char	**new_value;
	
	*dict = malloc(g_max * sizeof (struct s_node *));
	init_dict(*dict);
	while(i < file_size)
	{		
		if(is_digit(file_string[i]) && (i < file_size))
		{
			new_node = malloc(sizeof (struct s_node));
			new_node->next = 0;
			new_node->key = *new_key;
			new_node->value = *new_value;
			process_line(file_string, &i, new_node, *dict);

		}
		i++;
	}
	display(*dict);
}
