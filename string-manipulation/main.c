#include <stdio.h>
#include "misc.h"
 
int main()
{
    char *emp_name = "Guru Prasad Patel";
    int length = string_length(emp_name);

    printf("Empolye name : %s, length : %d\n", emp_name, length);

    return 0;
}
