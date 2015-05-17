/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 20:36:20 by adebray           #+#    #+#             */
/*   Updated: 2015/05/17 01:16:45 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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

int		is_reverse_sort(t_ps *list)
{
	int	tmp;

	while (list)
	{
		tmp = list->nbr;
		list = list->next;
		if (list && list->nbr >= tmp)
			return (0);
	}
	return (1);
}

int		get_listsize(t_ps *list)
{
	int	i;

	i = 0;
	if (!list)
		return (0);
	else
	{
		while (list)
		{
			list = list->next;
			i += 1;
		}
		return (i);
	}
}

int		get_listmin(t_ps *list)
{
	int	i;

	i = INT_MAX;
	if (!list)
		return (0);
	while (list)
	{
		if (list->nbr < i)
			i = list->nbr;
		list = list->next;
	}
	return (i);
}

int		get_listmax(t_ps *list)
{
	int	i;

	i = INT_MIN;
	if (!list)
		return (0);
	while (list)
	{
		if (list->nbr > i)
			i = list->nbr;
		list = list->next;
	}
	return (i);
}
