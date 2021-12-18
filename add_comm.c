#include "monty.h"

/**
 * add_comm - adds ints on stack
 *@stack: stack head
 *@line_number: input
 *
 * Return: void.
 */

void add_comm(stack_t **stack, unsigned int line_number)
{
	stack_t *hold;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		fclose(global.fd);
		free(global.opcode);
		free_all(*stack);
		exit(EXIT_FAILURE);
	}
	hold = (*stack);
	(*stack) = (*stack)->next;
	(*stack)->n += (*stack)->prev->n;
	(*stack)->prev = NULL;
	free(hold);
}
