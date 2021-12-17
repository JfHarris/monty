#include "monty.h"

/**
 * pall_comm - print all
 *@sh: stack head
 *@input: input
 *
 * Return: void.
 */

void pall_comm(stack_t **sh, unsigned int input)
{
	stack_t *hold = (*sh);

	void(input);

	while (hold)
	{
		printf("%d\n", hold->n);
		hold = hold->next;
	}
}
