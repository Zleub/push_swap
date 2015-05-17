/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 04:17:50 by adebray           #+#    #+#             */
/*   Updated: 2015/05/17 01:29:48 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <time.h>
#define INSTR_OP 11

void	iter_list(t_ps *head, void (*p)(t_ps *))
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

int		build(int argc, char **argv)
{
	int		nbr;
	int		i;

	nbr = 0;
	g_head = NULL;
	g_end = NULL;
	if (argv[1] && ft_strcmp(argv[1], "-v"))
	{
		g_env.verbose = 0;
		i = 1;
	}
	else
	{
		g_env.verbose = 1;
		i = 2;
	}
	while (i < argc)
	{
		create(check(argv[i]));
		i += 1;
		nbr += 1;
	}
	return (nbr);
}

int		main(int argc, char **argv)
{
	int		count;
	int		nbr;

	if (argc == 1)
		return (0);
	nbr = build(argc, argv);
	g_env.min = INT_MAX;
	g_env.max = INT_MIN;
	iter_list(g_head, seek_min);
	iter_list(g_head, seek_max);
	count = 0;
	while (!is_sort(g_head) || g_end)
	{
		if (count != 0)
			ft_printf(" ");
		do_something(nbr);
		if (g_env.verbose)
		{
			print_list1();
			print_list2();
		}
		count += 1;
	}
	ft_printf("\ncount: %d\n", count);
	return (0);
}
