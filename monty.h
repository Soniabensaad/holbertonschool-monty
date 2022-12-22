#ifndef MONTY_H
#define MONTY_H
#define delim  " \n\t"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

char *val;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void apply(char *conter, stack_t **stack, unsigned int count);
void free_stack(stack_t *stack);
void add_node(stack_t **stack, int n);
void push(stack_t **stack, unsigned int counter);
void add(stack_t **stack, unsigned int counter);
void pall(stack_t **stack, __attribute__((unused)) unsigned int counter);
void pint(stack_t **stack, unsigned int counter);
void pop(stack_t **stack, unsigned int counter);
void swap(stack_t **stack, unsigned int counter);
void p_nop(__attribute__((unused)) stack_t **stack,
                   __attribute__((unused)) unsigned int count);
void sub(stack_t **stack, unsigned int counter);
void div(stack_t **stack, unsigned int counter);


#endif