/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 04:17:50 by adebray           #+#    #+#             */
/*   Updated: 2015/03/06 12:24:24 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

typedef struct s_ps		t_ps;

struct		s_ps
{
	int		*nbr;
	t_ps	*next;
	t_ps	*prev;
};

t_ps		*g_head;
t_ps		*g_mid;

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	return (0);
}
