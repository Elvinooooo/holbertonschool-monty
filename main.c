#include "monty.h"

int main(int argc, char *argv[])
{
    stack_t *stack = NULL;
    FILE *file;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    process_file(file, &stack);
    free_stack(&stack);
    fclose(file);

    exit(EXIT_SUCCESS);
}
