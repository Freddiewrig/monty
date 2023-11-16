#include "monty.h"
/**
 * push - Pushes an element onto the stack
 * @stack: Pointer to the top of the stack
 * @value: Value to be pushed onto the stack
 *
 * Return: None
 */
void push(stack_t **stack, int value)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Memory allocation error\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}

/**
 * pall - Prints all the values on the stack
 * @stack: Pointer to the top of the stack
 *
 * Return: None
 */
void pall(stack_t *stack)
{
	while (stack != NULL)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
	}
}

/**
 * free_stack - Frees the memory allocated for the stack
 * @stack: Pointer to the top of the stack
 *
 * Return: None
 */
void free_stack(stack_t *stack)
{
	while (stack != NULL)
	{
		stack_t *temp = stack;

		stack = stack->next;
		free(temp);
	}
}
/**
 * read_instruction - Reads an instruction from a file
 * @file: Pointer to the file
 * @opcode: Buffer to store the opcode
 * @value: Pointer to store the value (for push opcode)
 *
 * Return: 1 if an instruction is successfully read, 0 if end of file
 */
int read_instruction(FILE *file, char *opcode, int *value)
{
	if (fscanf(file, "%s", opcode) == EOF)
	{
		return (0);
	}
	if (strcmp(opcode, "push") == 0)
	{
		if (fscanf(file, "%d", value) != 1)
		{
			fprintf(stderr, "Error: usage: push integer\n");
			exit(EXIT_FAILURE);
		}
	}
	return (1);
}

/**
 * process_instruction - Processes an instruction and performs the
 * corresponding operation
 * @stack: Pointer to the top of the stack
 * @opcode: Opcode to be processed
 * @value: Value associated with the opcode (for push opcode)
 *
 * Return: None
 */
void process_instruction(stack_t **stack, const char *opcode, int value)
{
	if (strcmp(opcode, "push") == 0)
	{
		push(stack, value);
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(*stack);
	}
	else
	{
		fprintf(stderr, "Unknown opcode: %s\n", opcode);
		exit(EXIT_FAILURE);
	}
}
