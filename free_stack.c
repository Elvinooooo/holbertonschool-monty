#include "monty.h"
/**
* free_stack - function that frees the stack
* @stack: the stack to bee freed
* Return: Nothing
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
