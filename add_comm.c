#include "monty.h"

/**
 * add_comm - adds ints on stack
 *@sh: stack head
 *@input: input
 *
 * Return: void.
 */

void add_comm(stack_t **sh, unsigned int input)
{
	stack_t *hold;

	if ((*sh) == NULL || (*sh)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", input);
		fclose(global.fd);
		free(global.opcode);
		free_all(*sh);
		exit(EXIT_FAILURE);
	}
	hold = (*sh);
	(*sh) = (*sh)->next;
	(*sh)->n += (*sh)->prev->n;
	(*sh)->prev = NULL;
	free(hold);
}
