#include <unistd.h>
#include <stdlib.h>

void	put_str(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

int	str_cmp(char *s1, char *s2)
{
	while (*s1 != '\0' && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

char	*make_number(char *original, int size, int mode)
{
	int		i;
	char	*new;

	i = 1;
	new = malloc(size * sizeof (char) + 1);
	if (mode == 1)
		new[0] = '1';
	if (mode == 2 || mode == 3)
		new[0] = original[0];
	while (i < size)
	{
		if (mode == 1 || mode == 3)
			new[i] = '0';
		if (mode == 2)
			new[i] = original[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

int	count_digits(char *string)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}
