#include "monty.h"

/**
 * free_stack - function that frees the stack
 * @stack: the stack to be freed
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
 * process_push - function that checks the token and in success calls the
 * push function. Otherwise frees the memory and closes the file with exit
 * @token: the token to be checked
 * @stack: the actual stack
 * @file: the file to be closed
 * @line: the line to be freed
 * Return: Nothing
 */
void process_push(char *token, stack_t **stack, FILE *file, char *line)
{
	int value;

	token = strtok(NULL, " \t\n\r");
	if (token != NULL)
	{
		value = atoi(token);
		push(stack, value);
	}
	else
	{
		fprintf(stderr, "Error: Invalid push command: %s", line);
		fclose(file);
		free(line);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
}

