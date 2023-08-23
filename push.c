#include "main.h"

/**
 * push - Pushes an element onto the stack.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number where the push opcode is encountered.
 */
void push(stack_t **stack, unsigned int line_number)
{
	if (arguments_missing)
	{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	fclose(bus.file);
	free(bus.content);
	free_stack(*stack);
	exit(EXIT_FAILURE);
	}

	int value = atoi(argument);

	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)

	{
	fprintf(stderr, "Error: malloc failed\n");
	fclose(bus.file);
	free(bus.content);
	free_stack(*stack);
	exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
	(*stack)->prev = new_node;

	*stack = new_node;
}
