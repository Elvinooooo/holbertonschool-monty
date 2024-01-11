#include "monty.h"
/**
 *pint - function that prints the value at the top of stack
 *@stack:  the actual stack
 *@line_number:  for handling errors showing line number
 *@file:  the opened file;
 *@line: the buffer
 *Return: Nothing
*/

void pint(stack_t **stack, unsigned int line_number, FILE *file, char *line)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(file);
		free(line);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
