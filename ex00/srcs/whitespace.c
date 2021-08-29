int	is_whitespace(char c)
{
	if ((c == '\t') || c == '\v' || c == '\r'
		|| c == '\n' || c == ' ' || c == ':')
	{
		return (1);
	}
	return (0);
}

void	skip_whitespace(char *str, int *index)
{
	int	i;

	i = 0;
	while (is_whitespace(str[i + *index]))
	{
		i++;
	}
	*index += i;
}
