#include "dict.c"

#include "help_functions/help_functions.h"
#include "dict/processing/dict_processing.h"
#include "constants.h"


/* To display the contents of Hash map */
/*
void display_hash_map(struct s_node **dict)
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
}*/

void fill_dict(int argc, char **argv, struct s_node ***dict)
{
	int			fd;
	char		*file_string;

	if(argc == 2)
		fd = open("numbers.dict", O_RDONLY);
	else if(argc == 3)
		fd = open(argv[1], O_RDONLY);
	else
		write(1, "Error\n", 6);
	
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
		if(skip == 1)
		{

		new = make_number(string, 1, 2);
		index_hash = calculate_hash(new, &temp, 0);
		value = find(dict[index_hash], new);
					put_str(value);
					write(1, " ", 1);


		temp = 0;
														
		if(digit_count > 1)
		{
			new = make_number(string, digit_count, 1);
			index_hash = calculate_hash(new, &temp, 0);
			value = find(dict[index_hash], new);
			put_str(value);

			f(string + skip, 0, dict);
		}
		}else if(skip == 2)
		{
			if(string[0] == '0')
			{
				f(string + 1, 1, dict);
			}else
			{		temp = 0;

				if(string[0] == '1')
				{
					new = make_number(string, 2, 2);
					index_hash = calculate_hash(new, &temp, 0);
					value = find(dict[index_hash], new);
					put_str(value);
					//write(1, " ", 1);
					f(string + 2, 1, dict);

				}else{
					new = make_number(string, 2, 3);
					index_hash = calculate_hash(new, &temp, 0);
					value = find(dict[index_hash], new);
					put_str(value);
					f(string + 1, 1, dict);
				}

			}

		}else if(skip == 3){
			new = make_number(string, 1, 2);
			index_hash = calculate_hash(new, &temp, 0);
			value = find(dict[index_hash], new);
			put_str(value);
			write(1, " ", 1);

			temp = 0;
			new = make_number(string, 3, 1);
			index_hash = calculate_hash(new, &temp, 0);
			value = find(dict[index_hash], new);
			put_str(value);

			f(string + 1, 1, dict);
		}			

	}else if(string[0] == '0')
	{
		f(string + 1, 1, dict);
	}

}


void	display_number(int argc, char **argv, struct s_node **dict)
{
	char *string;
	
	if(argc == 2)
		string = argv[1];
	else if(argc == 3)
		string = argv[2];
	else
		write(1, "Error\n", 6);

	f(string, 0, dict);	
}

