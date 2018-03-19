#include <stdio.h>
#include "misc.h"
 
/*function definition*/
void myFunc(void)
{
    printf("Body of myFunc function.\n");
}


int string_length(char *str)
{
        int length_count = 0;
        while(*str != '\0'){
                str++;
                length_count++;
        }

        return length_count;
}

