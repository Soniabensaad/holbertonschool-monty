#ifndef MONTY_H
#define MONTY_H

/* Libraries */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
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
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct settings_s - settings for all the program
 * @file: file
 * @line: line
 * @stack: stack
 * @queue: false
 */
typedef struct settings_s
{
	FILE *file;
	char *line;
	stack_t *stack;
	_Bool queue;
} settings_t;

extern settings_t settings;



/* helpers */
void verify_args(int argc);
void open_and_read(char *f);
void exec_monty(stack_t **stack, char *opcode, int ln);
void set(void);
void clean(void);

/*Tools*/
int is_number(char *c);

/* Instructions */
void exec_pall(stack_t **stack, unsigned int line_number);
void exec_pop(stack_t **stack, unsigned int line_number);
void exec_pint(stack_t **stack, unsigned int line_number);
void exec_swap(stack_t **stack, unsigned int line_number);
void exec_nop(stack_t **stack, unsigned int line_number);

/* String Instructions */
void exec_pchar(stack_t **stack, unsigned int line_number);
void exec_pstr(stack_t **stack, unsigned int line_number);

/* Aritmetic Instructions */
void exec_div(stack_t **stack, unsigned int line_number);
void exec_mod(stack_t **stack, unsigned int line_number);
void exec_add(stack_t **stack, unsigned int line_number);
void exec_sub(stack_t **stack, unsigned int line_number);
void exec_mul(stack_t **stack, unsigned int line_number);

/* Rotations Instructions*/
void exec_rotl(stack_t **stack, unsigned int line_number);
void exec_rotr(stack_t **stack, unsigned int line_number);

/* Errors managements */

void error_handler(char *opcode, int errorcode, int ln);

/* FIFO AND LIFO */
void exec_stack(stack_t **stack, unsigned int line_number);
void exec_queue(stack_t **stack, unsigned int line_number);

/* Stack Management */

stack_t *push_stack(stack_t **head, const int n);
stack_t *push_queue(stack_t **head, const int n);
void fstack(stack_t *head);

#endif
