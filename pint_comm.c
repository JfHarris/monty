#include "monty.h"

/**
 * pint_comm - print int
 *@sh: stack head
 *@input: input
 *
 * Return: Always EXIT_SUCCESS.
 */

void pint_comm(stack_t **sh, unsigned int input)
{
	if (*sh)
	{
		printf("%d\n", (*sh)->n);
	}
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", input);
		fclose(global.fd);
		free(global.opcode);
		exit(EXIT_FAILURE);
	}
}
