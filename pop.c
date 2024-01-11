#include "monty.h"
/**
* pop -  function that deletes the element on the top of stack
* @stack: actual stack
* @line_number: the line number
* Return : nothing
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = top->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(top);
}

