/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 04:17:50 by adebray           #+#    #+#             */
/*   Updated: 2015/03/07 22:33:22 by adebray          ###   ########.fr       */
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

#include <time.h>
#define INSTR_OP 8

typedef struct s_stack	t_stack;

struct					s_stack
{
	void				(*p)(void);
	t_stack				*next;
};

t_stack					*g_stackhead = NULL;

void		print_stack(void)
{
	t_stack *tmp;

	tmp = g_stackhead;
	while (tmp)
	{
		ft_printf("%p\n", tmp->p);
		tmp = tmp->next;
	}
}

void		push_stack(t_stack *elem)
{
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

void	(*t[INSTR_OP])(void);

int		main(int argc, char **argv)
{
	int		i;

	i = 1;
	g_head = NULL;
	g_end = NULL;
	while (i < argc)
	{
		create(check(argv[i]));
		i += 1;
	}

	void	(*t[INSTR_OP])(void);
	int nbr;

	t[0] = push_l1;
	t[1] = push_l2;
	t[2] = swap_l1;
	t[3] = swap_l2;
	t[4] = rotate_l1;
	t[5] = rotate_l2;
	t[6] = reverse_l2;
	t[7] = reverse_l2;
	srand(time(NULL));
	while (!is_sort(g_head) || g_end)
	{
		nbr = rand() % INSTR_OP;
		t[nbr]();
		push_stack(new_stack(t[nbr]));
		// print_list1();
		// print_list2();
		usleep(800);
	}
	print_stack();
	return (0);
}

