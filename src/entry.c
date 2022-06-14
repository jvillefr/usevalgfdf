/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:55:59 by jvillefr          #+#    #+#             */
/*   Updated: 2022/06/09 12:28:06 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../include/fdf.h"

int	abs_of_val(int val)
{
	if (val < 0)
		val = -val;
	return (val);
}

int	get_x(char *c_data)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (c_data[i])
	{
		if (c_data[i] == '\n')
			x++ ;
		i++;
	}
	return (x);
}

int	get_y(char *c_data)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	if (c_data)
	{
		while (c_data[i] != '\n' && c_data[i] != '\0')
		{
			if (c_data[i] != 32 && c_data[i] != '\n')
			{
				y++;
				while (c_data[i] != 32 && c_data[i] != '\n' && c_data[i])
					i++;
			}
			if (c_data[i] == 32)
			{
				while (c_data[i] == 32)
					i++;
			}
		}
	}
	return (y);
}
