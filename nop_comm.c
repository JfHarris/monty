#include "monty.h"

/**
 * nop_comm - nop command
 *@stack: stack head
 *@line_number: where commands are entered
 *
 * Return: void.
 */

void nop_comm(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	free(global.opcode);
	global.opcode = malloc(sizeof(char) * 2);

	if (global.opcode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(global.fd);
		free_all(*stack);
		exit(EXIT_FAILURE);
	}
	global.opcode[0] = '\n';
	global.opcode[1] = '\0';
}
