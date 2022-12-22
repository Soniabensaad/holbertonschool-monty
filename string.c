#include "monty.h"
/*
*/
int is_numeric(char *s)
{
    int i = 0;
    if (!s)
    {
        return (0);
    }
    while (s[i])
    {
        if (i == 0 && s[i] == '-')
        {
            i++;
            continue;
        }
        if (s[i] < '0' || s[i] > '9')
        {
            return (0);
        }
        i++;
    }
    return (1);
  
    

}