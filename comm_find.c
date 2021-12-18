#include "monty.h"

/**
 * comm_find - finds command
 *@opcode: opcode
 *@stack: stack head
 *@line_number: input
 *
 * Return: stack head.
 */

stack_t *comm_find(char *opcode, stack_t **stack, unsigned int line_number)
{
	int x;
	instruction_t instructions[] = {
		{"pint", pint_comm}, {"pall", pall_comm},
		{"pop", pop_comm}, {"nop", nop_comm},
		{"add", add_comm}, {"swap", swap_comm},
		{NULL, NULL} };

	if (opcode[0] == '#')
	{
		return (*stack);
	}
	for (x = 0 ; instructions[x].opcode != NULL ; x++)
	{
		if (strcmp(opcode, instructions[x].opcode) == 0)
		{
			break;
		}
	}
	if (instructions[x].opcode == NULL)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		free_gen_error(*stack);
	}
	instructions[x].f(stack, line_number);
	return (*stack);
}
