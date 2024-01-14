#include "monty.h"
/**
 * push - Function that pushes an element onto the stack
 * @stack: The stack where the value should be pushed
 * @value: Value to be pushed
 * Return: Nothing
 */
void push(stack_t **stack, char* value, unsigned int line_number)
{
    stack_t *new_node = malloc(sizeof(stack_t));

    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    if (is_num(value) == 1 && value != NULL)
    {
        new_node->n = atoi(value);
        new_node->prev = NULL;
        new_node->next = NULL;
    }
    else
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        free(new_node);
        exit(EXIT_FAILURE);
    }

    if (*stack == NULL)
    {
        *stack = new_node;
    }
    else
    {
        new_node->next = *stack;
        (*stack)->prev = new_node;
        *stack = new_node;
    }
}
