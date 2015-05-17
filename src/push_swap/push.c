/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 17:36:43 by adebray           #+#    #+#             */
/*   Updated: 2015/05/16 21:51:59 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void		push_list(t_ps **dst, t_ps **src)
{
	t_ps	*swp;

	if (!*src)
		return ;
	swp = *src;
	*src = (*src)->next;
	if (*dst)
		swp->next = *dst;
	else
		swp->next = NULL;
	*dst = swp;
}

void			pa(void)
{
	ft_printf("pa");
	push_list(&g_end, &g_head);
}

void			pb(void)
{
	ft_printf("pb");
	push_list(&g_head, &g_end);
}
