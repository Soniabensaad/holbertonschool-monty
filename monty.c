#include "monty.h"
int main(int argc, char **argv[])
{
    st_tools.file = NULL;
    st_tools.type = "stack";
    st_tools.instructions = NULL;

   
    if (argc != 2)
    {
        puts_stderr("USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
   file_handling (argv[1]);
    return (0);
}

    
   

    
    

