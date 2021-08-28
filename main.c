#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
int size = 0;         /* Determines the no. of elements present in Hash Table */
int max = 100;	      /* Determines the maximum capacity of Hash Table array */

//Key pair entries for use in the hashmap linked list dictionary
struct s_node{
	struct	s_node *next;
	char	*key;
	char	*value;
};


/* This function creates an index corresponding to the every given key */
int hashcode(int key)
{
	return (key % max);
}


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

/* For initializing the Hash Table */
void init_array(struct s_node *dict)
{
	int i;
	for (i = 0; i < max; i++)
        {
		dict[i].next = 0;
		dict[i].key = 0;
		dict[i].value = 0;
	}
 
}

 

void insert(struct s_node** dict, char *key, char *value)
{
  	float n = 0.0;     
	/* n => Load Factor, keeps check on whether rehashing is required or not */
 
	//int index = hashcode(key);  
	int index = 0;
 
	/* Extracting Linked List at a given index */
	struct s_node *list = dict[index];
 
	/* Creating an item to insert in the Hash Table */
	struct s_node *item = (struct s_node*) malloc(sizeof(struct s_node));
	item->key = key;
	item->value = value;
	item->next = NULL;
 
	if (list == NULL) 
        {
		/* Absence of Linked List at a given Index of Hash Table */
 
		printf("Inserting %s(key) and %s(value) \n", key, value);
		dict[index] = item;
		size++;
 
	}
        else 
        {
		/* A Linked List is present at given index of Hash Table */
 
		int find_index = find(list, key); 
		if (find_index == -1) 
                {
			/*
			 *Key not found in existing linked list
			 *Adding the key at the end of the linked list
			*/
			struct s_node *last;
			last = dict[index];
			while(last->next != 0)
			{
				last = last->next;
			}
			last->next = item;
			size++;
 
		}else 
                 {
			/*
			 *Key already present in linked list
			 *Updating the value of already existing key
			*/
 
			struct s_node *element = get_element(list, find_index);
			element->value = value;
 
		}
 
	}
}

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