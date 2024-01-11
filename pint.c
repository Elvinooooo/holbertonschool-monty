#include "monty.h"
void pint(stack_t **stack, unsigned int line_number, FILE *file, char *line)
{
	if (stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(file);
		free(line);
		free_stack(stack);
		exit(EXIT_FAILURE);
    }
	printf("%d\n", (*stack)->n);
}
