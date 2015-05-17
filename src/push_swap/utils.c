/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/17 01:08:54 by adebray           #+#    #+#             */
/*   Updated: 2015/05/17 01:59:51 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	die(int val)
{
	if (val == 2)
		ft_printf("Error %d: not a number\n", val);
	else
		ft_printf("Error %d\n", val);
	exit (val);
}

void	create(int nbr)
{
	t_ps	*head;
	t_ps	*new;

	if (!(new = (t_ps *)malloc(sizeof(t_ps))))
		die(-1);
	ft_bzero(new, sizeof(t_ps));
	new->nbr = nbr;
	if (!g_head)
		g_head = new;
	else
	{
		head = g_head;
		while (head->next)
			head = head->next;
		head->next = new;
	}
}

void	to_die(char *str)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (!ft_isdigit(str[i]) && str[i] != '-')
			die(2);
		if (i > 10)
			die(2);
		i += 1;
	}
	if (i == 10 && get_max_int(str))
		die(2);
	if (i == 11 && get_min_int(str))
		die(2);
}

int		check(char *str)
{
	int		nbr;
	t_ps	*head;

	head = g_head;
	to_die(str);
	nbr = ft_atoi(str);
	while (head)
	{
		if (nbr == head->nbr)
			die(-1);
		head = head->next;
	}
	return (nbr);
}
