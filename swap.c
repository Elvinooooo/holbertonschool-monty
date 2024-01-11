#include "monty.h"
/**
*swap- function that swaps the top two elements of the stack.
*@stack: the actual stack
*@line_number:line number
*Return:Nothing
*/
void swap(stack_t **stack, unsigned int line_number)
{
	int len = 0;
	stack_t *current = *stack;

	while (current)
	{
		len++;
		current = current->next;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	int temp = (*stack)->n;

	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
