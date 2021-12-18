#include "monty.h"

/**
 * pall_comm - print all
 *@stack: stack head
 *@line_number: input
 *
 * Return: void.
 */

void pall_comm(stack_t **stack, unsigned int line_number)
{
	stack_t *hold = (*stack);

	(void)line_number;

	while (hold)
	{
		printf("%d\n", hold->n);
		hold = hold->next;
	}
}
