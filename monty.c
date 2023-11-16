#include "monty.h"
/**
 * main - entry point
 * @argc: arg
 * @argv: args
 * Return: 0 success
 */
int main(int argc, char *argv[])
{
	char opcode[100];
	int value;
	stack_t *stack = NULL;
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_instruction(file, opcode, &value))
	{
		process_instruction(&stack, opcode, value);
	}
	fclose(file);
	free_stack(stack);
	return (0);
}
