#include "monty.h"

/**
 * new_node - creates new node
 *@opcode: opcode
 *@stack: stack head
 *@line_number: input
 *
 * Return: pointer to stack head.
 */

stack_t *new_node(char *opcode, stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	int x;
	char buff[1020];

	if (strcmp(opcode, "push-\0") == 0 || strcmp(opcode, "push-\n") == 0)
		free_push_err(line_number, *stack);
	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}

	for (x = 0 ; opcode[x + 5] != '\0' ; x++)
	{
		if (isdigit(opcode[x + 5]) || opcode[x + 5] == '-')
			buff[x] = opcode[x + 5];
		else
		{
			free(new);
			free_push_err(line_number, *stack);
		}
	}
	buff[x] = '\0';
	new->n = atoi(buff);
	new->prev = NULL;

	if ((*stack) == NULL)
	{
		new->next = NULL;
		(*stack) = new;
	}
	else
	{
		new->next = (*stack);
		(*stack)->prev = new;
		(*stack) = new;
	}
	return (*stack);
}
