#include "monty.h"

/**
 * pop_comm - removes top of stack
 *@stack: stack head
 *@line_number: input
 *
 * Return: void.
 */

void pop_comm(stack_t **stack, unsigned int line_number)
{
	stack_t *hold = (*stack);

	if (*stack)
	{
		(*stack) = (*stack)->next;
		free(hold);
		if (*stack)
		{
			(*stack)->prev = NULL;
		}
	}
	else
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		fclose(global.fd);
		free(global.opcode);
		exit(EXIT_FAILURE);
	}
}
