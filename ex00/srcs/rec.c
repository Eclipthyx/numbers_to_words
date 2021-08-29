#include "../include/dict.h"
#include "../include/help_functions.h"
#include "../include/key.h"
#include "../include/dict_operations.h"
#include <unistd.h>

void	rec(char *string, int size, struct s_node **dict, int flag);

void	display_word(struct s_object obj, int number_size, int mode)
{
	char	*new;
	char	*value;
	int		temp;
	int		index_hash;

	if (obj.flag == 1)
		write(1, " ", 1);
	temp = 0;
	new = make_number(obj.string, number_size, mode);
	index_hash = calculate_hash(new, &temp);
	value = find(obj.dict[index_hash], new);
	put_str(value);
}

void	rec_1(struct s_object obj, int size, int digit_count)
{
	if (obj.string[0] != '0')
	{
		display_word(obj, 1, 2);
		obj.flag = 1;
		if (digit_count > 1)
			display_word(obj, digit_count, 1);
	}
	else if (*(obj.string - 1) != '0' || *(obj.string - 2) != '0')
	{
		if (digit_count > 1)
			display_word(obj, digit_count, 1);
		if (size == 1)
			display_word(obj, digit_count, 2);
	}
	rec(obj.string + 1, size, obj.dict, 1);
}

void	rec_2(struct s_object obj, int size, int digit_count)
{
	if (obj.string[0] == '1' && obj.string[1] != '0')
	{
		display_word(obj, 2, 2);
		obj.flag = 1;
		if (digit_count > 3)
		{
			display_word(obj, digit_count - 1, 3);
		}
		rec(obj.string + 2, size, obj.dict, 1);
	}
	else if (obj.string[0] >= '1')
	{
		display_word(obj, 2, 3);
		rec(obj.string + 1, size, obj.dict, 1);
	}		
}

void	rec_3(struct s_object obj, int size)
{
	if (obj.string[0] != '0')
	{
		display_word(obj, 1, 2);
		obj.flag = 1;
		display_word(obj, 3, 1);
	}
	rec(obj.string + 1, size, obj.dict, 1);
}

void	rec(char *string, int size, struct s_node **dict, int flag)
{
	int					digit_count;
	int					skip;
	struct s_object		obj;

	obj.flag = flag;
	obj.string = string;
	obj.dict = dict;
	digit_count = count_digits(obj.string);
	skip = (digit_count - 1) % 3 + 1;
	if ((digit_count > 0) && (obj.string[0] != '\0'))
	{
		if (skip == 1)
			rec_1(obj, size, digit_count);
		else if (skip == 2)
			rec_2(obj, size, digit_count);
		else if (skip == 3)
			rec_3(obj, size);
	}
}
