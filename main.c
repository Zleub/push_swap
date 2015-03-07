/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 04:17:50 by adebray           #+#    #+#             */
/*   Updated: 2015/03/07 17:45:38 by adebray          ###   ########.fr       */
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
		if (!ft_isdigit(str[i]))
			die(-1);
		i += 1;
	}
	nbr = ft_atoi(str);
	while (head)
	{
		if (nbr == head->nbr)
			die(1);
		head = head->next;
	}
	return (nbr);
}

#include <time.h>
#define INSTR_OP 8

int		main(int argc, char **argv)
{
	void	(*t[INSTR_OP])(void);
	int		i;
	int nbr;

	i = 1;
	g_head = NULL;
	g_end = NULL;
	while (i < argc)
	{
		create(check(argv[i]));
		i += 1;
	}
	t[0] = push_l1;
	t[1] = push_l2;
	t[2] = swap_l1;
	t[3] = swap_l2;
	t[4] = rotate_l1;
	t[5] = rotate_l2;
	t[6] = reverse_l2;
	t[7] = reverse_l2;
	srand(time(NULL));
	while (42)
	{
		nbr = rand() % INSTR_OP;
		t[nbr]();
		print_list1();
		print_list2();
		usleep(800);
	}
	return (0);
}

