#include "main.h"

/**
 * pall - Prints all the values on the stack.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number where the pall opcode is encountered.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	while (current)
	{
	printf("%d\n", current->n);
	current = current->next;
	}
	(void)line_number;
}
