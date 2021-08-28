static	int	const	max = 1000;

//Key pair entries for use in the hashmap linked list dictionary
struct s_node{
	struct	s_node *next;
	char	*key;
	char	*value;
};

/* For initializing the dictionary */
void init_dict(struct s_node **dict)
{
	int i;
	for (i = 0; i < max; i++)
        {
		dict[i]->next = 0;
		dict[i]->key = 0;
		dict[i]->value = 0;
	}
}
