#include "monty.h"

/**
 * free_push_err - pint error and free
 *@line_number: input from whence error arises
 *@stack: stack head
 *
 * Return: void
 */

void free_push_err(unsigned int line_number, stack_t *stack)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	fclose(global.fd);
	free(global.opcode);
	free_all(stack);
	exit(EXIT_FAILURE);
}

/**
 * free_mal_malloc - malloc error function
 *@stack: stack head
 *
 * Return: void
 */

void free_mal_malloc(stack_t *stack)
{
	fprintf(stderr, "Error: malloc failed\n");
	fclose(global.fd);
	free(global.opcode);
	free_all(stack);
	exit(EXIT_FAILURE);
}

/**
 * free_all - frees entire stack
 *@stack: stack head
 *
 * Return: void.
 */

void free_all(stack_t *stack)
{
	stack_t *hold;

	while (stack != NULL)
	{
		hold = stack;
		stack = stack->next;
		free(hold);
	}
}

/**
 * free_gen_error - frees in case of general error
 *@stack: stack head
 *
 * Return: void.
 */

void free_gen_error(stack_t *stack)
{
	fclose(global.fd);
	free(global.opcode);
	free_all(stack);
	exit(EXIT_FAILURE);
}
