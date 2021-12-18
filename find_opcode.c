#include "monty.h"
#define COMM_END ((*st)[x] != ' ' && (*st)[x] != '\n' && (*st)[x] != '\0')

/**
 * find_opcode - finds opcode
 *@st: input string = command to execute
 *
 * Return: string
 */

char *find_opcode(char **st)
{
	int x = 0, y = 0, end = 1;
	char *opcode;

	opcode = malloc(sizeof(char) * (strlen(*st) + 1));
	if (opcode == NULL)
	{
		free(*st), *st = NULL;
		return (NULL);
	}
	while ((*st)[x] == ' ')
		x++;
	if ((*st)[x] == '\0' || (*st)[x] == '\n')
	{
		free(*st), *st = NULL;
		opcode[y] = '\n';
		opcode[y + 1] = '\0';
		return (opcode);
	}
	for (y = 0 ; COMM_END ; x++, y++)
		opcode[y] = (*st)[x];
	if ((*st)[x] == '\0')
		end = 0;
	opcode[y] = '\0';
	if (strcmp(opcode, "push") == 0 && end)
	{
		opcode[y] = ' ';
		while ((*st)[x] == ' ')
			x++;
		if ((*st)[x] == '\0' || (*st)[x] == '\n')
		{
			free(*st), *st = NULL;
			opcode[y] = '\0';
			return (opcode);
		}
		for (y += 1 ; COMM_END ; x++, y++)
			opcode[y] = (*st)[x];
		opcode[y] = '\0';
	}
	free(*st), *st = NULL;
	return (opcode);
}
