int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

int	set_key(char *str, int *index, char **key)
{
	int	result;
	int	i;
	int	j;

	i = 0;
	result = 0;
	while (is_digit(str[i + *index]))
	{
		result = (str[i + *index] * (i + 1) + result) % max;
		i++;
	}
	*key = malloc(i * sizeof (char) + 1);
	j = 0;
	while (j < i)
	{
		(*key)[j] = str[j + *index];
		j++;
	}
	(*key)[j] = '\0';
	*index += i;
	return (result);
}
