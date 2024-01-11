#include "monty.h"
/**
*swap- function that swaps the top two elements of the stack.
*@stack: the actual stack
*@line_number:line number
*Return:Nothing
*/
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next->n;

	(*stack)->next->n = (*stack)->n;
	(*stack)->n = temp;
}
