#ifndef MONTY_H
#define MONTY_H



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
typedef struct file_s
{
	FILE *fp;
	char *line;
	stack_t *stack;
	_Bool queue;
} file_t;

extern file_t file;




void verify_args(int argc);
void open_and_read(char *f);
void apply_monty(stack_t **stack, char *opcode, int ln);
void get(void);
void total_free(void);


int is_number(char *c);


void apply_pall(stack_t **stack, unsigned int line_number);
void apply_pop(stack_t **stack, unsigned int line_number);
void apply_pint(stack_t **stack, unsigned int line_number);
void apply_swap(stack_t **stack, unsigned int line_number);
void apply_nop(stack_t **stack, unsigned int line_number);


void apply_pchar(stack_t **stack, unsigned int line_number);
void apply_pstr(stack_t **stack, unsigned int line_number);


void apply_div(stack_t **stack, unsigned int line_number);
void apply_mod(stack_t **stack, unsigned int line_number);
void apply_add(stack_t **stack, unsigned int line_number);
void apply_sub(stack_t **stack, unsigned int line_number);
void apply_mul(stack_t **stack, unsigned int line_number);


void apply_rotl(stack_t **stack, unsigned int line_number);
void apply_rotr(stack_t **stack, unsigned int line_number);



void error_handler(char *opcode, int code, int ln);


void apply_stack(stack_t **stack, unsigned int line_number);
void apply_queue(stack_t **stack, unsigned int line_number);



stack_t *push_stack(stack_t **head, const int n);
stack_t *push_queue(stack_t **head, const int n);
void fstack(stack_t *head);

#endif
