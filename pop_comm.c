#include "monty.h"

/**
 * pop_comm - removes top of stack
 *@sh: stack head
 *@input: input
 *
 * Return: void.
 */

void pop_comm(stack_t **sh, unsigned int input)
{
	stack_t *hold = (*sh);

	if (*sh)
	{
		(*sh) = (*sh)->next;
		free(hold);
		if (*sh)
		{
			(*sh)->prev = NULL;
		}
	}
	else
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", input);
		fclose(global.fd);
		free(global.opcode);
		exit(EXIT_FAILURE);
	}
}
