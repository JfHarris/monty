#define _POSIX_SOURCE
#include "monty.h"

/**
 * check_file - checks if able to open file
 *@argc: # of input args
 *@argv: arg array = program to exec
 *
 * Return: file.
 */

FILE *check_file(int argc, char *argv[])
{
	int check;

	global.opcode = NULL;
	global.fd = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	check = open(argv[1], O_RDONLY);

	if (check == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	global.fd = fdopen(check, "r");

	if (global.fd == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	return (global.fd);
}
