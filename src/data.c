/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:52:28 by jvillefr          #+#    #+#             */
/*   Updated: 2022/06/13 09:04:28 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../include/fdf.h"

void	render(t_map map, t_mlx *mlx)
{
	int	x;
	int	y;

	x = 0;
	while (x < map.x_size)
	{
		y = 0;
		while (y + 1 < map.y_size)
		{
			if (x != 0 && y == 0)
				draw_line(map.dot[x][y], map.dot[x - 1][y],
					mlx->image, map);
			draw_line(map.dot[x][y], map.dot[x][y + 1], mlx->image, map);
			y++;
			if (x != 0 && y != 0)
				draw_line(map.dot[x][y], map.dot[x -1][y],
					mlx->image, map);
		}
		x++;
	}
	mlx_put_image_to_window(mlx->server, mlx->window, mlx->image->image, 0, 0);
}

void	add_x(t_dot *start, t_dot *end, int *d, int *p)
{
	if (*p > 0)
	{
		*p += 2 * d[1] - 2 * d[0];
		if (start->x_pos < end->x_pos)
			start->x_pos++;
		else
			start->x_pos--;
		if (start->y_pos < end->y_pos)
			start->y_pos++;
		else
			start->y_pos--;
	}
	else if (*p <= 0)
	{
		*p += 2 * d[1];
		if (start->x_pos < end->x_pos)
			start->x_pos++;
		else
			start->x_pos--;
	}
}

void	add_y(t_dot *start, t_dot *end, int *d, int *p)
{
	if (*p > 0)
	{
		*p += 2 * d[0] - 2 * d[1];
		if (start->y_pos < end->y_pos)
			start->y_pos++;
		else
			start->y_pos--;
		if (start->x_pos < end->x_pos)
			start->x_pos++;
		else
			start->x_pos--;
	}
	else if (*p <= 0)
	{
		*p += 2 * d[0];
		if (start->y_pos < end->y_pos)
			start->y_pos++;
		else
			start->y_pos--;
	}
}

int	same_pos(t_dot start, t_dot end)
{
	if (start.x_pos != end.x_pos)
		return (0);
	if (start.y_pos != end.y_pos)
		return (0);
	return (1);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i <= map->x_size)
	{
		free(map->dot[i]);
		i++;
	}
	free (map->dot);
}
