#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
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

/**
 * struct var_s - holds opcode and fd
 * @opcode: opcode
 * @fd: file description
 *
 * Description: holds pointers as global vars
 *
 */

typedef struct var_s
{
	char *opcode;
	FILE *fd;
} var_t;

extern var_t global;

char *find_opcode(char **string);
stack_t *new_node(char *opcode, stack_t **sh, unsigned int input);
FILE *check_file(int argc, char *argv[]);
void nop_comm(stack_t **sh, unsigned int input);
void free_push_err(unsigned int input, stack_t *sh);
void free_mal_malloc(stack_t *sh);
void free_all(stack_t *sh);
void free_gen_error(stack_t *sh);
stack_t *comm_find(char *opcode, stack_t **sh, unsigned int input);
void pint_comm(stack_t **sh, unsigned int input);
void pall_comm(stack_t **sh, unsigned int input);
void pop_comm(stack_t **sh, unsigned int input);
void swap_comm(stack_t **sh, unsigned int input);
void add_comm(stack_t **sh, unsigned int input);
int main_monty(int argc, char *argv[]);


#endif
