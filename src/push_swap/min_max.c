/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/17 01:57:33 by adebray           #+#    #+#             */
/*   Updated: 2015/05/17 01:57:38 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		get_max_int(char *str)
{
	if (str[0] > '2')
		return (1);
	if (str[1] > '1')
		return (1);
	if (str[2] > '4')
		return (1);
	if (str[3] > '7')
		return (1);
	if (str[4] > '4')
		return (1);
	if (str[5] > '8')
		return (1);
	if (str[6] > '3')
		return (1);
	if (str[7] > '6')
		return (1);
	if (str[8] > '4')
		return (1);
	if (str[9] > '7')
		return (1);
	return (0);
}

int		get_min_int(char *str)
{
	if (str[1] > '2')
		return (1);
	if (str[2] > '1')
		return (1);
	if (str[3] > '4')
		return (1);
	if (str[4] > '7')
		return (1);
	if (str[5] > '4')
		return (1);
	if (str[6] > '8')
		return (1);
	if (str[7] > '3')
		return (1);
	if (str[8] > '6')
		return (1);
	if (str[9] > '4')
		return (1);
	if (str[10] > '8')
		return (1);
	return (0);
}
