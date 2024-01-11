#include "monty.h"
/**
* main - The main function
* @argc: Argument count
* @argv: Argument vector
* Return: 0 on success, EXIT_FAILURE on failure
*/
int main(int argc, char *argv[])
{
	FILE *file = fopen(argv[1], "r");
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	process_file(file, &stack);
	fclose(file);
	return (0);
}
