#include "dict/dict.h"
#include "help_functions/help_functions.h"
#include "dict/processing/dict_processing.h"
#include "constants.h"


void fill_dict(int argc, char **argv, struct s_node ***dict)
{
	int		fd;
	char	*file_string;
	int		file_size;
	int		i;
	int		index;

	if(argc == 2)
		fd = open("numbers.dict", O_RDONLY);
	else if(argc == 3)
		fd = open(argv[1], O_RDONLY);
	else
		write(1, "Error\n", 6);
	file_string = malloc(BUFFER_SIZE * sizeof (char));
	file_size = read(fd, file_string, BUFFER_SIZE);
	i = 0;
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


void f2(char *string, struct s_node **dict, int number_size, int mode)
{
	char *new;
	char *value;
	int temp = 0;
	int index_hash;

	new = make_number(string, number_size, mode);
	index_hash = calculate_hash(new, &temp);
	value = find(dict[index_hash], new);
	put_str(value);
	write(1, " ", 1);
}
void f(char *string, int size, struct s_node **dict)
{
	int digit_count;
	int skip;
	digit_count = count_digits(string);
	skip = (digit_count - 1) % 3 + 1;
	printf("[%d]", skip);

	if((digit_count > 0) && (string[0] != '\0'))
	{
		if(skip == 1)
		{
			//write(1, " ONE ", 5);
	
				f2(string, dict, 1, 2);										
				if(digit_count > 1)
				{
					f2(string, dict, digit_count, 1);
				}
			
			//write(1, " TWO ", 5);

			f(string + 1, 0, dict);
		}else if(skip == 2)
		{
			if(string[0] == '1' && string[1] != '0')
			{
				f2(string, dict, 2, 2);
				f(string + 2, 1, dict);
			}	
			else if(string[0] == '0')
			{
				f(string + 1, 1, dict);
			}else if(string[0] > '1')
			{
				if(string[1] == '0')
				{
					f2(string, dict, 2, 3);
					f2(string + 1, dict, digit_count - 1, 1);
					f(string + 2, 1, dict);
				}
				else
				{
					f2(string, dict, 2, 3);
					f(string + 1, 1, dict);
				}
			}
		}else if(skip == 3){
			f2(string, dict, 1, 2);
			f2(string, dict, 3, 1);
			f(string + 1, 1, dict);
		}			

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

