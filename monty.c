#include "monty.h"
/**
 * main - Monty interpreter main function
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 on success, EXIT_FAILURE on failure
 */
// Add this function to monty.c
void free_stack(stack_t **stack)
{
	stack_t *current = *stack;
	while (current != NULL)
	{
		stack_t *temp = current;
		current = current->next;
		free(temp);
	}
	*stack = NULL;
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	FILE *file = fopen(argv[1], "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;

	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		parse_line(file, &stack, line_number);
	}
	free_stack(&stack);
	free(line);
	fclose(file);
	return (0);
}
