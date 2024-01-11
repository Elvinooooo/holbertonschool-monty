#include "monty.h"
/**
* main - The main function
* @argc: Argument count
* @argv: Argument vector
* Return: 0 on success, EXIT_FAILURE on failure
*/
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
	size_t line_size = 0;

	while (getline(&line, &line_size, file) != -1)
	{
		char *token = strtok(line, " \t\n\r");

		if (token != NULL && strcmp(token, "push") == 0)
			process_push(token, &stack, file, line);
		else if (strcmp(token, "pall") == 0)
			pall(&stack);
	}
	fclose(file);
	free(line);
	free_stack(&stack);
	return (0);
}
