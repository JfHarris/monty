#define _GNU_SOURCE
#include <stdio.h>
#include "monty.h"
var_t global;

/**
 * main_monty - function to read and execute monty code
 * @argc: number of args from input
 * @argv: names of executable program
 *
 * Return: 0 on success.
 */

int main(int argc, char *argv[])
{
	char *string = NULL;
	stack_t *stack = NULL;
	unsigned int line_number;
	size_t buff;
	ssize_t check;

	line_number = 1;

	global.fd = check_file(argc, argv);

	while (1)
	{
		check = getline(&string, &buff, global.fd);
		if (check == -1)
		{
			free(string);
			break;
		}
		global.opcode = find_opcode(&string);
		if (global.opcode == NULL)
			free_mal_malloc(stack);
		if (strncmp(global.opcode, "push", 5) == 0)
		{
			stack = new_node(global.opcode, &stack, line_number);
			if (stack == NULL)
				free_gen_error(stack);
		}
		else if (strcmp(global.opcode, "push") == 0)
			free_push_err(line_number, stack);
		else
		{
			stack = comm_find(global.opcode, &stack, line_number);
		}
		free(global.opcode);
		line_number++;
	}
	fclose(global.fd);
	free_all(stack);
	return (0);
}
