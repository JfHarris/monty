#include "monty.h"

/**
 * swap_comm - swaps top two elements of stack
 *@sh: stack head
 *@input: input
 *
 * Return: void.
 */

void swap_comm(stack_t **sh, unsigned int input)
{
	int hold;

	if ((*sh) == NULL || (*sh)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", input);
		fclose(global.fd);
		free(global.opcode);
		free_all(*sh);
		exit(EXIT_FAILURE);
	}
	hold = (*sh)->n;
	(*sh)->n = (*sh)->next->n;
	(*sh)->next->n = hold;
}
