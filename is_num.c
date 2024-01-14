#include "monty.h"

/**
 * is_num - Checks is it number.
 * @opcode: Value to be checked.
 * Return: 1 if true, 0 otherwise.
 */
int is_num(char *opcode)
{
	int i = 0;

	if (opcode == NULL)
		return (0);

	while (opcode[i])
	{
		if (opcode[0] == '-')
		{
			i++;
			continue;
		}
		if (!isdigit(opcode[i]))
			return (0);
		i++;
	}
	return (1);
}
