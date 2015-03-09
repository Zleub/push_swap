/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 17:37:24 by adebray           #+#    #+#             */
/*   Updated: 2015/03/07 19:21:05 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void		print_list(t_ps *list)
{
	if (!list)
		return ;
	if (list->next)
	{
		print_list(list->next);
		ft_printf(" ");
	}
	ft_printf("%d", list->nbr);
}

void			print_list1(void)
{
	ft_printf("\tl1: ");
	print_list(g_head);
	ft_printf("\n");
}

void			print_list2(void)
{
	ft_printf("\tl2: ");
	print_list(g_end);
	ft_printf("\n");
}
