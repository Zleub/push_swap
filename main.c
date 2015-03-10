/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 04:17:50 by adebray           #+#    #+#             */
/*   Updated: 2015/03/10 00:30:54 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	die(int val)
{
	ft_printf("Error %d\n", val);
	exit (val);
}

void	create(int nbr)
{
	t_ps	*new;

	if (!(new = (t_ps *)malloc(sizeof(t_ps))))
		die(-1);
	ft_bzero(new, sizeof(t_ps));
	new->nbr = nbr;
	if (!g_head)
		g_head = new;
	else
	{
		t_ps *head;
		head = g_head;
		while (head->next)
			head = head->next;
		head->next = new;
	}
}

int		check(char *str)
{
	int		i;
	int		len;
	int		nbr;
	t_ps	*head = g_head;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (!ft_isdigit(str[i]) && str[i] != '-')
			die(2);
		i += 1;
	}
	nbr = ft_atoi(str);
	while (head)
	{
		if (nbr == head->nbr)
			die(-1);
		head = head->next;
	}
	return (nbr);
}

int		is_sort(t_ps *list)
{
	int	tmp;

	while (list)
	{
		tmp = list->nbr;
		list = list->next;
		if (list && list->nbr <= tmp)
			return (0);
	}

	return (1);
}

int		get_l2lem(void)
{
	int		i;
	t_ps	*tmp;

	if (!g_end)
		return (0);
	tmp = g_end;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i += 1;
	}
	return (i);
}

#include <time.h>
#define INSTR_OP 11

typedef struct s_stack	t_stack;

struct					s_stack
{
	void				(*p)(void);
	t_stack				*next;
};

t_stack					*g_stackhead = NULL;
t_stack					*g_laststack = NULL;

void	(*t[INSTR_OP])(void); ///!\ WARNING

void		print_stack(void)
{
	t_stack *tmp;

	tmp = g_stackhead;
	while (tmp)
	{
		if (tmp->p == t[0])
			ft_printf("pa");
		else if (tmp->p == t[1])
			ft_printf("pb");
		else if (tmp->p == t[2])
			ft_printf("sa");
		else if (tmp->p == t[3])
			ft_printf("sb");
		else if (tmp->p == t[4])
			ft_printf("ra");
		else if (tmp->p == t[5])
			ft_printf("rb");
		else if (tmp->p == t[6])
			ft_printf("rra");
		else if (tmp->p == t[7])
			ft_printf("rrb");
		else if (tmp->p == t[8])
			ft_printf("ss");
		else if (tmp->p == t[9])
			ft_printf("rr");
		else if (tmp->p == t[10])
			ft_printf("rrr");
		tmp = tmp->next;
		if (tmp)
			ft_printf(" ");
	}
}

void		push_stack(t_stack *elem)
{
	g_laststack = elem;
	if (!g_stackhead)
		g_stackhead = elem;
	else
	{
		t_stack *tmp;

		tmp = g_stackhead;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = elem;
	}
}

t_stack		*new_stack(void (*p)(void))
{
	t_stack	*new;

	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		die (666);
	new->p = p;
	new->next = NULL;
	return (new);
}

void		print_env(void)
{
	ft_printf("g_env.min: %d\n", g_env.min);
	ft_printf("g_env.max: %d\n", g_env.max);
	ft_printf("g_env.mid: %d\n", g_env.mid);
	ft_printf("g_env.middle: %d\n", g_env.middle);
}

void		iter_list(t_ps *head, void (*p)(t_ps *))
{
	t_ps *tmp;

	tmp = head;
	while (tmp)
	{
		p(tmp);
		tmp = tmp->next;
	}
}

void	seek_min(t_ps *tmp)
{
	if (tmp->nbr < g_env.min)
		g_env.min = tmp->nbr;
}

void	seek_max(t_ps *tmp)
{
	if (tmp->nbr > g_env.max)
		g_env.max = tmp->nbr;
}

// void	get_mid(void)
// {
// 	g_env.mid = ;
// }

void	do_something_random(void)
{
	int nbr = rand() % INSTR_OP;

	t[nbr]();
	push_stack(new_stack(t[nbr]));
}

int		areMinMaxgood(void)
{
	int		min;
	int		max;
	t_ps	*tmp;

	min = 0;
	max = 0;
	tmp = g_end;
	while (tmp)
	{
		if (tmp->nbr == g_env.min)
			min = 1;
		if (tmp->nbr == g_env.max)
			max = 1;

		if (tmp->nbr == g_env.max && min)
			return (0);
		tmp = tmp->next;
	}
	tmp = g_head;
	while (tmp)
	{
		if (tmp->nbr == g_env.min && !max)
			min = 1;
		if (tmp->nbr == g_env.max && !min)
			return (0);
		tmp = tmp->next;
	}
	return (min);
	// if (min && max)
	// 	return (1);
	// else
	// 	return (0);
}

// Assume that min and max are good when max is upper than min
// min should be on bottom of list_2
// max on bottom of list_1

void	rrr(void)
{
	rra();
	rrb();
}

void	ss(void)
{
	sa();
	sb();
}

void	rr(void)
{
	ra();
	rb();
}

int		isLastMin(t_ps *list)
{
	t_ps	*tmp;
	int		i;

	tmp = list;
	i = INT_MAX;
	if (!tmp)
		return (0);
	while (tmp)
	{
		if (tmp->nbr < i)
			i = tmp->nbr;
		tmp = tmp->next;
	}
	if (list && list->nbr == i)
		return (1);
	else
		return (0);
}

int		is_notAlone(t_ps *list)
{
	if (!list || !list->next)
		return (0);
	else
		return (1);
}

void	do_something(void)
{
	// int nbr = rand() % INSTR_OP;

	// t[nbr]();
	// if (isMaxmissplaced())

	// else if (isMinmissplaced())

	// if (isLastMin(g_head) && is_notAlone(g_head))
	// {
	// 	ra();
	// 	return ;
	// }
	// if (isLastMin(g_end) && is_notAlone(g_end))
	// {
	// 	rb();
	// 	return ;
	// }
	if (!areMinMaxgood())
	{
		rrr();
		return ;
	}
	else
	{
	// ft_printf("isMaxmissplaced: %d\n", isMaxmissplaced());

	// ft_printf("isMinmissplaced: %d\n", isMinmissplaced());


		int nbr = rand() % INSTR_OP;
		if (!g_end)
		{
			while (nbr == 0 || nbr == 3 || nbr == 5 || nbr == 7)
				nbr = rand() % INSTR_OP;
		}
		if (!g_head)
		{
			while (nbr == 1 || nbr == 2 || nbr == 4 || nbr == 6)
				nbr = rand() % INSTR_OP;
		}
		t[nbr]();
		// if (g_laststack && g_laststack->p == t[nbr])
		// 	ft_printf("same movement twice\n");
		push_stack(new_stack(t[nbr]));
	}
	// print_list1();
	// print_list2();
	// usleep(800 * 400);
}

void	get_something(void)
{
	char	*lines;

	lines = (char *)malloc(8);
	while (get_next_line(0, &lines) > 0)
	{
		if (!ft_strcmp(lines, "sa"))
			sa();
		if (!ft_strcmp(lines, "sb"))
			sb();
		if (!ft_strcmp(lines, "pa"))
			pa();
		if (!ft_strcmp(lines, "pb"))
			pb();
		if (!ft_strcmp(lines, "ra"))
			ra();
		if (!ft_strcmp(lines, "rb"))
			rb();
		if (!ft_strcmp(lines, "rra"))
			rra();
		if (!ft_strcmp(lines, "rrb"))
			rrb();
		if (!ft_strcmp(lines, "ss"))
			ss();
		if (!ft_strcmp(lines, "rr"))
			rr();
		if (!ft_strcmp(lines, "rrr"))
			rrr();
		print_list1();
		print_list2();
	}
	free(lines);
}

int		main(int argc, char **argv)
{
	int		i;

	if (ft_strcmp(argv[1], "-v"))
	{
		g_env.verbose = 0;
		i = 1;
	}
	else
	{
		g_env.verbose = 1;
		i = 2;
	}
	g_head = NULL;
	g_end = NULL;
	while (i < argc)
	{
		create(check(argv[i]));
		i += 1;
	}

	g_env.min = INT_MAX;
	g_env.max = INT_MIN;
	iter_list(g_head, seek_min);
	iter_list(g_head, seek_max);
	// get_mid();
	print_env();

	// void	(*t[INSTR_OP])(void);

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

	srand(time(NULL));

	print_list1();
	print_list2();

	int count = 0;
	while (!is_sort(g_head) || g_end)
	{
		do_something();
		// get_something();
		count += 1;
	}
	print_stack();
	ft_printf("\ncount: %d\n", count);
	print_list1();
	print_list2();
	return (0);
}

