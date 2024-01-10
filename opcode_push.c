#include "monty.h"
/**
 * push - Pushes an element onto the stack
 * @stack: Double pointer to the head of the stack
 * @value: Value to push onto the stack
 * @line_number: Line number in the Monty byte code file
 *
 * Description: Allocates a new node, initializes its value, and adds it to
 * the top of the stack. Updates the pointers accordingly.
 * If allocation fails, an error message is printed, and the program exits.
 */
void push(stack_t **stack, int value)
{
	stack_t *new_node, *temp;
	
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
	printf("Stack after push: ");
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d ",temp->n);
		temp = temp->next;
	}
	printf("\n");
}
