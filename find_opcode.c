#include "monty.h"
#define COMM_END ((*string)[x] != ' ' && (*string)[x] != '\n' && (*string)[x] != '\0')

/**
 * find_opcode - finds opcode
 *@string: input string = command to execute
 *
 * Return: string
 */

char *find_opcode(char **string)
{
	int x = 0, y = 0;
	int end = 1;
	char *opcode;

	opcode = malloc(sizeof(char) * (strlen(*string) + 1));

	if (opcode == NULL)
	{
		free(*string), *string = NULL;
		return (NULL);
	}

	while ((*string)[x] == ' ')
		x++;
	if ((*string)[x] == '\0' || (*string)[x] == '\n')
	{
		free(*string), *string = NULL;
		opcode[y] = '\n';
		opcode[y + 1] = '\0';
		return (opcode);
	}
	for (y = 0 ; END_COMM ; x++, y++)
		opcode[y] = (*string)[x];
	if ((*string)[x] == '\0')
		end = 0;
	opcode[y] = '\0';
	if (strcmp(opcode, "push") == 0 && end)
	{
		opcode[y] = ' ';
		while ((*string)[x] == ' ')
			x++;
		if ((*string)[x] == '\0' || (*string)[x] == '\n')
		{
			free(*string), *string = NULL;
			opcode[y] = '\0';
			return (opcode);
		}
		for (y += 1 ; END_COMM ; x++, y++)
			opcode[y] = (*string)[x];
		opcode[y] = '\0';
	}
	free(*string), *string = NULL;
	return (opcode);
}
