#include "monty.h"
/**
 * pall - Prints all values on the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the Monty byte code file
 *
 * Description: Traverses the stack and prints the integer value of each
 * element on a new line. The traversal starts from the top of the stack.
 */
void pall(stack_t **stack)
{
	stack_t *current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
