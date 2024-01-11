#include "monty.h"
/**
 * pall - Prints the values on the stack followed by a new line
 * @stack: Pointer to the stack
 * Return: Nothing
 */
void pall(stack_t **stack)
{
	if (*stack == NULL)
		return;
	stack_t *current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
