#include "monty.h"

/**
 * swap_comm - swaps top two elements of stack
 *@stack: stack head
 *@line_number: input
 *
 * Return: void.
 */

void swap_comm(stack_t **stack, unsigned int line_number)
{
	int hold;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		fclose(global.fd);
		free(global.opcode);
		free_all(*stack);
		exit(EXIT_FAILURE);
	}
	hold = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = hold;
}
