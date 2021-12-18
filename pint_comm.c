#include "monty.h"

/**
 * pint_comm - print int
 *@stack: stack head
 *@line_number: input
 *
 * Return: Always EXIT_SUCCESS.
 */

void pint_comm(stack_t **stack, unsigned int line_number)
{
	if (*stack)
	{
		printf("%d\n", (*stack)->n);
	}
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(global.fd);
		free(global.opcode);
		exit(EXIT_FAILURE);
	}
}
