#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "file.c"

int main(int argc, char **argv)
{
    struct      s_node **dict;

	
	fill_dict(argc, argv, dict);
	//Index in table pointed to by fd (like pointing to numbers.dict)  
}