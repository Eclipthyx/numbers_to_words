#include "../include/dict.h"
#include "../include/help_functions.h"
#include "../include/key.h"
#include "../include/dict_operations.h"
#include <unistd.h>

void	rec(char *string, int size, struct s_node **dict);

void	display_word(char *string, struct s_node **dict,
					 int number_size, int mode)
{
	char	*new;
	char	*value;
	int		temp;
	int		index_hash;

	temp = 0;
	new = make_number(string, number_size, mode);
	index_hash = calculate_hash(new, &temp);
	value = find(dict[index_hash], new);
	put_str(value);
	write(1, " ", 1);
}

void	rec_1(char *string, struct s_node **dict, int size, int digit_count)
{
	if (string[0] != '0')
	{
		display_word(string, dict, 1, 2);
		if (digit_count > 1)
			display_word(string, dict, digit_count, 1);
	}
	else if (*(string - 1) != '0' || *(string - 2) != '0')
	{
		if (digit_count > 1)
			display_word(string, dict, digit_count, 1);
		if (size == 1)
			display_word(string, dict, digit_count, 2);
	}
	rec(string + 1, size, dict);
}

void	rec_2(char *string, struct s_node **dict, int size)
{
	if (string[0] == '1' && string[1] != '0')
	{
		display_word(string, dict, 2, 2);
		rec(string + 2, size, dict);
	}
	else if (string[0] >= '1')
	{
		display_word(string, dict, 2, 3);
	}		
	rec(string + 1, size, dict);
}

void	rec_3(char *string, struct s_node **dict, int size)
{
	if (string[0] != '0')
	{
		display_word(string, dict, 1, 2);
		display_word(string, dict, 3, 1);
	}
	rec(string + 1, size, dict);
}

void	rec(char *string, int size, struct s_node **dict)
{
	int	digit_count;
	int	skip;

	digit_count = count_digits(string);
	skip = (digit_count - 1) % 3 + 1;
	if ((digit_count > 0) && (string[0] != '\0'))
	{
		if (skip == 1)
			rec_1(string, dict, size, digit_count);
		else if (skip == 2)
			rec_2(string, dict, size);
		else if (skip == 3)
			rec_3(string, dict, size);
	}
}
