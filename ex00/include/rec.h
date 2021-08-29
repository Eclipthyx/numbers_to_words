#ifndef REC_H
# define REC_H
# include "dict.h"

void	rec(char *string, int size, struct	s_node **dict, int flag);
void	rec_1(struct s_object obj, int size, int digit_count);
void	rec_2(struct s_object obj, int size);
void	rec_3(struct s_object obj, int size);
#endif
