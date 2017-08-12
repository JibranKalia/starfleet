#include "header.h"

struct s_stack *initStack()
{
	t_stack *top = malloc(sizeof(t_stack));
	top->item = NULL;
	return (top);
}

void push(struct s_stack *stack, int idx)
{
	if (stack->item == NULL)
	{
		t_item *newItem = malloc(sizeof(t_item));
		newItem->next = NULL;
		newItem->idx = idx;
		stack->item = newItem;
		return;
	}
	t_item *newItem = malloc(sizeof(t_item));
	newItem->next = stack->item;
	newItem->idx = idx;
	stack->item = newItem;
}

int pop(struct s_stack *stack)
{
	if (stack->item == NULL)
		return (0);
	t_item *top = stack->item;
	if (top->next == NULL)
	{
		stack->item = NULL;
		return (top->idx);
	}
	stack->item = top->next;
	return (top->idx);
}

char *console(void)
{
	char buffer[256];
	bzero(buffer, 256);
	char *input = malloc(sizeof(char) * 256);
	t_stack		*stack = initStack();
	int		len;
	int		idx;
	while (1)
	{
		fgets(input, 256, stdin);
		len = strlen(input);
		if (len > 0 && input[len-1] == '\n') input[len-1] = 0;
		if (input[0] == '?')
		{
			idx = strlen(buffer);
			strcat(buffer, input + 1);
			push(stack, idx);
		}
		else if (!strcmp(input, "UNDO"))
		{
			idx = pop(stack);
			buffer[idx] = 0;
		}
		else if (!strcmp(input, "SEND"))
			return (strdup(buffer));
		if (buffer[0] != 0)
			printf("%s\n", buffer);
		bzero(input, 256);
	}
	return (NULL);
}
