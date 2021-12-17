#include "monty.h"

/**
 * comm_find - finds command
 *@opcode: opcode
 *@sh: stack head
 *@input: input
 *
 * Return: stack head.
 */

stack_t *comm_find(char *opcode, stack_t **sh, unsigned int input)
{
	int x;
	var_t comms[] = {
		{"pint", pint_comm}, {"pall", pall_comm},
		{"pop", pop_comm}, {"nop", nop_comm},
		{"add", add_comm}, {"swap", swap_comm},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
	{
		return (*sh);
	}
	for (x = 0 ; comms[x].opcode != NULL ; x++)
	{
		if (strcmp(opcode, comms[x].opcode) == 0)
		{
			break;
		}
	}
	if (comms[x].opcode == NULL)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", input, opcode);
		free_gen_error(*sh);
	}
	comms[x].f(sh, input);
	return (*sh);
}
