#include "monty.h"
/**
 * pint - Prints the value at the top of the stack
 * @stack: Pointer to the top of the stack
 *
 * Return: None
 */
void pint(stack_t *stack)
{
	if (stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", __LINE__);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", stack->n);
}
