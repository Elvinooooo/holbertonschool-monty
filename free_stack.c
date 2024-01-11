#include "monty.h"
/**
* free_stack - function that frees the stack
* @stack: the stack to bee freed
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
