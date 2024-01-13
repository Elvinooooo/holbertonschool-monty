#include "monty.h"
/**
 * push - Function that pushes an element onto the stack
 * @stack: The stack where the value should be pushed
 * @value: Value to be pushed
 * Return: Nothing
 */
void push(stack_t **stack, int value)
{
    printf("DEBUG: Pushing value: %d\n", value);  // Debugging output

    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->n = value;
    new_node->prev = NULL;

    if (*stack == NULL)
    {
        new_node->next = NULL;
        *stack = new_node;
    }
    else
    {
        new_node->next = *stack;
        (*stack)->prev = new_node;
        *stack = new_node;
    }
}
