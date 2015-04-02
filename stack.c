#include "stack.h"

t_stack		*new_stack(void(*p)(void))
{
	t_stack	*new;

	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		exit(666);
	new->p = p;
	new->next = NULL;
	return (new);
}

void		print_stack(t_stack *head)
{
	if (head)
	{
		printf("[%p]", head->p);
		print_stack(head->next);
	}
}

void		push_stack(t_stack **head, t_stack *elem)
{
	if (!(*head))
		(*head) = elem;
	else
	{
		t_stack *tmp;

		tmp = (*head);
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = elem;
	}
}
