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
	int value;
	unsigned int line_number = 0;

	while (getline(&line, &line_size, file) != -1)
	{
		line_number++;
		char *token = strtok(line, " \t\n\r");

		if (token != NULL && strcmp(token, "push") == 0)
		{
			token = strtok(NULL, " \t\n\r");
			if (token != NULL)
			{
				value = atoi(token);
				push(&stack, value);
			}
			else
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_number);
				fclose(file);
				free(line);
				free_stack(&stack);
				exit(EXIT_FAILURE);
			}
		}
		else if (strcmp(token, "pall") == 0)
			pall(&stack);
		else if (strcmp(token, "pint") == 0)
			pint(&stack, line_number, file, line);
		else
		{
				fprintf(stderr, "L%u: unknown instruction %s\n", line_number,line);
				exit(EXIT_FAILURE);
		}
	}
	fclose(file);
	free(line);
	free_stack(&stack);
	return (0);
}
