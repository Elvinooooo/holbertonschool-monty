#include "monty.h"
/**
 * parse_line - Parses a line from the Monty byte code file
 * @file: File stream to read from
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number being processed
*/
void parse_line(FILE *file, stack_t **stack, unsigned int line_number)
{
	char *opcode;
	int value;
	char *value_str;
	char *line = NULL;
	size_t len = 0;

	if (getline(&line, &len, file) == -1)
	{
		free(line);
		fprintf(stderr, "Error: Unable to read line %u\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (line[strlen(line) - 1] == '\n')
		line[strlen(line) - 1] = '\0';
	opcode = strtok(line, " \t\n");
	if (!opcode || opcode[0] == '#')
	{
		free(line);
		return;
	}
	value_str = strtok(NULL, " \t\n");
	value = (value_str) ? atoi(value_str) : 0;
	if (strcmp(opcode, "push") == 0)
	{
		push(stack, value);
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(stack);
	}
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		free(line);
		exit(EXIT_FAILURE);
	}
	free(line);
}
