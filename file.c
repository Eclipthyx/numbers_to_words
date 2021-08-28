#include "dict.c"
#include "dict/dict.h"
#include "constants.h"

int	str_cmp(char *s1, char *s2)
{
	while (*s1 != '\0' && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char*)s1 - *(unsigned char*)s2);
}

char *find(struct s_node *node, char *key)
{
	int retval = 0;
	struct s_node *ptr = node;
	while (ptr != 0) 
	{
		if (str_cmp(ptr->key, key) == 0)
		{
			return (ptr->value);
		}
  		ptr = ptr->next;
	}
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
void	process_line(char *str, int *index, struct s_node *new_node, struct s_node **dict)
{
	int	index_hash;
	char	**new_key;
	char	**new_value;

	new_node->next = 0;
	new_node->key = *new_key;
	new_node->value = *new_value;
	index_hash = set_key(str, index, &new_node->key);
	skip_whitespace(str, index);
	set_value(str, index, &new_node->value);
	insert(dict, new_node, index_hash);
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
			printf("%d, %s, %s",i,  dict[i]->key, dict[i]->value);
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
	
	file_string = malloc(BUFFER_SIZE * sizeof (char));

	int file_size = read(fd, file_string, BUFFER_SIZE);
	
	int		i = 0;
	int		index;
	
	*dict = malloc(g_max * sizeof (struct s_node *));
	init_dict(*dict);
	while(i < file_size)
	{		
		if(is_digit(file_string[i]) && (i < file_size))
		{
			struct	s_node* new_node;
			new_node = malloc(sizeof (struct s_node));
			process_line(file_string, &i, new_node, *dict);
		}
		i++;
	}
}

void make_number(char *original, char **copy, int size, int index)
{
	int i = 0;
	*copy = malloc(size * sizeof(char) + 1);
	while(i < size)
	{
		(*copy)[i] = original[i + index];
		i++;
	}
	(*copy)[i] = '\0';
}

char *make_number2(char *original, int size,  int index)
{
	int i;
	char *new;
	
	i = 0;
	new = malloc(size * sizeof(char) + 1);
	
	new[0] = original[index];
	i = 1;
	
	while(i < size)
	{
		new[i] = '0';
		i++;
	}
	new[i] = '\0';

	return new;
}

int count_digits(char *string)
{
	int i;
	i = 0;
	while(string[i] != '\0')
	{
		i++;
	}
	return i;
}


void f(char *string, int size, struct s_node **dict)
{
	int digit_count;
	char *new;
	char *value;
	int temp = 0;
	int index_hash;
	int skip;
	digit_count = count_digits(string);

	skip = (digit_count - 1) % 3 + 1;

	if((digit_count > 0)
		&& (string[0] != '0')
		&& (string[0] != '\0'))
	{
		new = make_number2(string, digit_count, 0);
		index_hash = calculate_hash(new, &temp, 0);
		value = find(dict[index_hash], new);
		printf("\n[%s]", value);
		printf("FIRST{%d}[%s]", (digit_count - 1) % 3 + 1, new);

		f(string + 1, 0, dict);
	}
	//make_number(string, &word, , index);
}


void	convert(int argc, char **argv, struct s_node **dict)
{
	char *string;
	int index;
	int size;
	int i;
	char *number;

	
	if(argc == 2)
	{
		string = argv[1];
	}else if(argc == 3)
	{
		string = argv[2];
	}else
	{
		write(1, "Error\n", 6);
	}
	size = 0;
	i = 0;
	while(string[size] != '\0')
	{		
		size++;
	}

	f(string, 0, dict);	

	
	//make_number2(orig, &new, digit_count, 0);
	//f(string, 0, size);
			//index = calculate_hash(string, &i, 0);

}

