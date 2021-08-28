int	is_alpha(char c)
{
	if ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z')
		|| (c == '-'))
	{
		return (1);
	}
	return (0);
}

void	set_value(char *str, int *index, char **value)
{
	int	i;
	int	j;

	i = 0;
	while (is_alpha(str[i + *index]))
	{
		i++;
	}
	*value = malloc(i * sizeof (char) + 1);
	j = 0;
	while (j < i)
	{
		(*value)[j] = str[j + *index];
		j++;
	}
	(*value)[j] = '\0';
	*index += i;
}
