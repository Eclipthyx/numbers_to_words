#include "constants.h"

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
    i = 0;
    while (i < g_max)
    {
		dict[i] = 0;
        i++;
	}
}
