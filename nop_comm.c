#include "monty.h"

/**
 * nop_comm - nop command
 *@sh: stack head
 *@input: where commands are entered
 *
 * Return: void.
 */

void nop_comm(stack_t **sh, unsigned int input)
{
	void s, input;

	free(global.opcode);
	global.opcode = malloc(sizeof(char) * 2);

	if (global.opcode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(global.fd);
		free_all(*sh);
		exit(EXIT_FAILURE);
	}
	global.opcode[0] = '\n';
	global.opcode[1] = '\0';
}
