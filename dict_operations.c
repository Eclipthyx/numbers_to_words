
static int size = 0;         /* Determines the no. of elements present in Hash Table */
static int max = 100;	      /* Determines the maximum capacity of Hash Table array */

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