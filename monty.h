#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
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

void xfpush(stack_t **head, unsigned int number);
void xfpall(stack_t **head, unsigned int number);
void xfpop(stack_t **head, unsigned int counter);
void xfswap(stack_t **head, unsigned int counter);
void xfadd(stack_t **head, unsigned int counter);
void xfnop(stack_t **head, unsigned int counter);
void xfreestack(stack_t *head);
void xaddnode(stack_t **head, int n);
void xaddqueue(stack_t **head, int n);
int execute(char *content, stack_t **head, unsigned int counter, FILE *file);

/**
 * struct bus_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct xbu_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  xbus_t;
extern xbus_t bus;

#endif