#include <stdio.h>

#include <push_swap.h>
#include "stack.h"
#include "tree.h"

void		(*t[11])(void);

void	die(int val)
{
	ft_printf("Error %d\n", val);
	exit (val);
}

void		print_tab(int i)
{
	while (i)
	{
		write(1, "  ", 2);
		i -= 1;
	}
}

void		print_op(void(*p)(void))
{
	if (p == NULL)
		ft_printf("[]");
	else if (p == t[0])
		ft_printf("[pa]");
	else if (p == t[1])
		ft_printf("[pb]");
	else if (p == t[2])
		ft_printf("[sa]");
	else if (p == t[3])
		ft_printf("[sb]");
	else if (p == t[4])
		ft_printf("[ra]");
	else if (p == t[5])
		ft_printf("[rb]");
	else if (p == t[6])
		ft_printf("[rra]");
	else if (p == t[7])
		ft_printf("[rrb]");
	else if (p == t[8])
		ft_printf("[ss]");
	else if (p == t[9])
		ft_printf("[rr]");
	else if (p == t[10])
		ft_printf("[rrr]");
}

void		print_instruct1(t_tree *head)
{
	static int	level;
	void	(*p)(void);
	// t_stack		*s;

	while (head)
	{
		if (!head->s)
			ft_printf("no s\n");
		if (!head->s->p)
			ft_printf("no p\n");
		p = head->s->p;
		print_op(p);
		if (head->branch)
		{
			level += 1;
			write(1, "\n", 1);
			print_tab(level);
			print_instruct1(head->branch);
			level -= 1;
		}
		head = head->next;
		if (head)
		{			write(1, "\n", 1);
			print_tab(level);
		}
		// else
		// 	ft_printf("\n");
	}
}

void		print_instruct2(t_tree *head)
{
	static int	level;
	void	(*p)(void);
	// t_stack		*s;

	if (head)
	{
		if (!head->s)
			ft_printf("no s\n");
		if (!head->s->p)
			ft_printf("no p\n");
		p = head->s->p;
		print_op(p);
		if (head)
		{
			// write(1, " ", 1);
			print_tab(level);
		}
		print_instruct2(head->next);
		if (head->branch)
		{
			level += 1;
			write(1, "\n", 1);
			// print_tab(level);
			print_instruct2(head->branch);
			level -= 1;
		}
		// else
		// 	ft_printf("\n");
	}
}

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	t[0] = pa;
	t[1] = pb;
	t[2] = sa;
	t[3] = sb;
	t[4] = ra;
	t[5] = rb;
	t[6] = rra;
	t[7] = rrb;
	t[8] = ss;
	t[9] = rr;
	t[10] = rrr;

	// int depth = 10;
	// int i;
	// int j;
	if (argc < 2)
		return (-1);

	// int i = 1;

	// t_stack *stack = NULL;

	// while (i < argc)
	// {
	// 	push_stack(&stack, new_stack(ft_atoi(argv[i])));
	// 	i += 1;
	// }

	// print_stack(stack);

	t_tree *head = make_branch(2);
	(void)head;
	// fill_branch(&head);

	printf("\n");
	print_instruct1(head);
	printf("\n");
	print_instruct2(head);
	return (0);
}
