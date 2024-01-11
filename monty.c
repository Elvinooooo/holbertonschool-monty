#include "monty.h"
/**
* free_stack - function that frees the stack
* @stack: the stack to bee freed
* Return: Nothing
*/
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

	while (getline(&line, &line_size, file) != -1)
	{
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
				fprintf(stderr, "Error: Invalid push command: %s", line);
				fclose(file);
				free(line);
				free_stack(&stack);
				exit(EXIT_FAILURE);
			}
		}
		else if (strcmp(token, "pall") == 0)
			pall(&stack);
	}
	fclose(file);
	free(line);
	free_stack(&stack);
	return (0);
}