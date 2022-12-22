#include "monty.h"
/*
*/
void puts_stderr(char *tmp)
{
    fputs(tmp, stderr);
    exit(EXIT_FAILURE);
}
/*
*/
void free_exit(void)
{
    free(st_tools.instructions);
    file_close();
    exit(EXIT_FAILURE);
}