#include "monty.h"

/**
 * free_pint - pint error and free
 *@input: input from whence error arises
 *@sh: stack head
 *
 * Return: void
 */

void free_push_err(unsigned int input, stack_t *sh)
{
	fprintf(stderr, "L%u: usage: push integer\n", input);
	fclose(global.fd);
	free(global.opcode);
	free_all(sh);
	exit(EXIT_FAILURE);
}

/**
 * free_mal_malloc - malloc error function
 *@sh: stack head
 *
 * Return: void
 */

void free_mal_malloc(stack_t *sh)
{
	fprintf(stderr, "Error: malloc failed\n");
	fclose(global.fd);
	free(global.opcode);
	free_all(sh);
	exit(EXIT_FAILURE);
}

/**
 * free_all - frees entire stack
 *@sh: stack head
 *
 * Return: void.
 */

void free_all(stack_t *sh)
{
	stack_t *hold;

	while (sh != NULL)
	{
		hold = sh;
		sh = sh->next;
		free(hold);
	}
}

/**
 * free_gen_error - frees in case of general error
 *@sh: stack head
 *
 * Return: void.
 */

void free_gen_error(stack_t *sh)
{
	fclose(global.fd);
	free(global.opcode);
	free_all(sh);
	exit(EXIT_FAILURE);
}
