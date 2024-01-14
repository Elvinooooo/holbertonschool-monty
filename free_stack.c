#include "monty.h"

/**
 * free_stack - Frees a stack.
 * @stack: Pointer to the top of the stack.
 * Return: Void.
 */
void free_stack(stack_t **stack)
{
    stack_t *temp;

    while (*stack != NULL)
    {
        temp = (*stack)->next;
        free(*stack);
        *stack = temp;
    }
}

