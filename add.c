#include "monty.h"
/**
* add -  function that adds the top two elements of the stack
* @stack: the actual stack
* @line_number: the line number
* Return: nothing
*/
void add(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}
