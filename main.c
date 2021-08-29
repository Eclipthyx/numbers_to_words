#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "file.c"
#include "constants.h"


int main(int argc, char **argv)
{
    struct      s_node **dict;

	
	fill_dict(argc, argv, &dict);
    display_number(argc, argv, dict);
    //display_hash_map(dict);
	//Index in table pointed to by fd (like pointing to numbers.dict)  
}