#ifndef _MONTY_H
#define _MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct stack_t_tools
{
        char *instructions;
        char *type;
        FILE *file;
} tools;
extern tools st_tools;
tools st_tools;
int main(int argc, char **argv[]);
/* handle file functions*/
void file_open(char *namefile);
void file_read(void);
void file_close(void);
void file_handling(char *namefile);
void apply(unsigned int *number_line, stack_t **stack);
void(*instruction_l)(stack_t **stack, unsigned int n);
void (*help_instruction(char *command))(stack_t ** stack, unsigned int number_line);
void puts_stderr(char *tmp);
void free_exit(void);
int is_numeric(char *s);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
int remove_node_start(stack_t **head, stack_t *current_node);










#endif /*_MONTY_H*/


