#ifndef DICT_H
# define DICT_H

struct	s_object{
	char			*string;
	struct s_node	**dict;
	int				flag;
};

struct s_node{
	struct s_node	*next;
	char			*key;
	char			*value;
};
#endif