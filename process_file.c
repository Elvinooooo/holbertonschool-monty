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
 * execute_opcode - Executes the specified Monty opcode.
 * @token: The opcode token to execute.
 * @stack: Pointer to the stack.
 * @line_number: Current line number in the Monty file.
 * @file: Pointer to the Monty file being processed.
 * @line: Current line being processed.
 */
void execute_opcode(char *token, stack_t **stack, unsigned int line_number,
					FILE *file, char *line)
{
	if (strcmp(token, "push") == 0)
	{
		token = strtok(NULL, " \t\n\r");
		if (token != NULL)
			push(stack, atoi(token));
		else
			push_error(line_number, file, line, stack);
	}
	else if (strcmp(token, "pall") == 0)
		pall(stack);
	else if (strcmp(token, "pint") == 0)
		pint(stack, line_number);
	else if (strcmp(token, "pop") == 0)
		pop(stack, line_number);
	else if (strcmp(token, "swap") == 0)
		swap(stack, line_number);
	else if (strcmp(token, "add") == 0)
		add(stack, line_number);
	else if (strcmp(token, "nop") == 0)
		nop(stack, line_number);
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, line);
		exit(EXIT_FAILURE);
	}
}

/**
* process_file -  Function that processes the codes in .m file
* @file: the opened file
* @stack: the actual stack
* Return: 0 on success, EXIT_FAILURE on failure
*/
void process_file(FILE *file, stack_t **stack)
{
	char *opcode, *token = NULL;
	size_t size = 0;
	int counter = 0;

	while (getline(&opcode, &size, file) != -1)
	{
		counter++;
		token = strtok(opcode, "\n\t\r ");
		if (token == NULL || *token == '#')
			continue;
		execute_opcode(token, stack, counter, file, opcode);
	}
	free(opcode);
}
