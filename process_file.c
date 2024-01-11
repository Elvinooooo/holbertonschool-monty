#include "monty.h"

/**
 * report_push_error - Function to report push error and exit
 * @line_number: Line number in the Monty file
 * @file: File being processed
 * @line: Current line being processed
 * @stack: Stack being operated on
 */
void push_error(unsigned int line_number, FILE *file,
				char *line, stack_t **stack)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	fclose(file);
	free(line);
	free_stack(stack);
	exit(EXIT_FAILURE);
}
/**
* process_file -  Function that processes the codes in .m file
* @file: the opened file
* @stack: the actual stack
* Return: 0 on success, EXIT_FAILURE on failure
*/
void process_file(FILE *file, stack_t **stack)
{
	char *line = NULL;
	size_t line_size = 0;
	int value;
	unsigned int line_number = 0;

	while (getline(&line, &line_size, file) != -1)
	{
		line_number++;
		if (line[0] == '#')
			continue;
		char *token = strtok(line, " \t\n\r");

		if (token != NULL)
		{
			if (strcmp(token, "push") == 0)
			{
				token = strtok(NULL, " \t\n\r");
				if (token != NULL)
				{
					value = atoi(token);
					push(stack, value);
				}
				else
					push_error(line_number, file, line, stack);
			}
			else if (strcmp(token, "pall") == 0)
				pall(stack);
			else if (strcmp(token, "pint") == 0)
				pint(stack, line_number, file, line);
			else if (strcmp(token, "pop") == 0)
				pop(stack, line_number);
			else if (strcmp(token, "swap") == 0)
				swap(stack, line_number);
			else
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", line_number, line);
				exit(EXIT_FAILURE);
			}
		}
	}
}
