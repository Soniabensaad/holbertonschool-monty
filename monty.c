#include "monty.h"
int main(int argc, char *argv[])
{
    char *c;
    size_t size = 0;
    ssize_t readl = 1;
    stack_t *stack = NULL;
    FILE *fp;
    unsigned int *a;
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    while (readl > 0)
    {
        c = NULL;
        readl = getline(&c, &size, fp);
        a++;
        if (readl > 0)
        {
          apply(c, &stack, *a, fp);  
        }
        free(c);

    }
    free_stack(stack);
    fclose(fp);
    return (0);

    
    

}