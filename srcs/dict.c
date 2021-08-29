#include "../include/constants.h"
#include "../include/dict.h"

void	init_dict(struct s_node **dict)
{
	int	i;

	i = 0;
	while (i < g_max)
	{
		dict[i] = 0;
		i++;
	}
}
