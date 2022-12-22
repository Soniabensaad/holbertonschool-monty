#include "monty.h"
/*
*/
void file_open(char *namefile)
{
    st_tools.file = fopen(namefile, "r");
    if (st_tools.file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", namefile);
        exit(EXIT_FAILURE);
    }
}
/*
*/
void file_read(void)
{
    size_t count_line = 0;
    unsigned int number_line = 0;
    stack_t *stack;
    stack = NULL;
    while ((getline(&st_tools.instructions, &count_line, st_tools.file)) != -1)
    {
        apply(&number_line, &stack);
    }
    clear_stack(stack);
    free(st_tools.instructions);
    /*
    */
}
void file_close(void)
{
    if (st_tools.file)
    {
        fclose(st_tools.file);
    }
    
}
void file_handling(char *namefile)
{
    file_open(namefile);
    file_read();
    file_close();
}



