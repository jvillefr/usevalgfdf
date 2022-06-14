/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:31:58 by jvillefr          #+#    #+#             */
/*   Updated: 2022/06/09 15:06:42 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../include/fdf.h"

//set up higher dot on map

int	get_z_coordonate(char *c_data, int i)
{
	int	z_pos;

	z_pos = 0;
	if (c_data[i] >= 33 && c_data[i] <= 126)
		z_pos = ft_atoi(c_data + i);
	return (z_pos);
}

void	draw_line(t_dot start, t_dot end, t_data *img, t_map map)
{
	int	d[2];
	int	p;

	start.y_pos -= start.z_pos * (map.base);
	end.y_pos -= end.z_pos * (map.base);
	d[0] = abs_of_val(end.x_pos - start.x_pos);
	d[1] = abs_of_val(end.y_pos - start.y_pos);
	p = 2 * d[1] - d[0];
	while (!(same_pos(start, end)))
	{
		my_mlx_pixel_put(img, start.x_pos, start.y_pos, YELLOW);
		if (d[0] > d[1])
			add_x(&start, &end, d, &p);
		else
			add_y(&start, &end, d, &p);
	}
}

//calculate coordonate for each dot on map

void	set_xy_coordonate(t_map *map, int x, int y)
{
	if (!y)
	{	
		if (x > y)
		{
			map->dot[x][y].x_pos = map->dot[0][0].x_pos - \
			((3 * map->base) * x);
			map->dot[x][y].y_pos = map->dot[0][0].y_pos + \
			((2 * map->base) * x);
		}
	}
	else
	{
		map->dot[x][y].x_pos = map->dot[x][y - 1].x_pos + (3 * map->base);
		map->dot[x][y].y_pos = map->dot[x][y - 1].y_pos + (2 * map->base);
	}
}

// set dot on map

void	fill_map_data(t_map *map, char *c_data)
{
	int		x;
	int		y;
	long	i;

	x = 0;
	y = 0;
	i = 0;
	while (c_data[i])
	{
		set_xy_coordonate(map, x, y);
		map->dot[x][y].z_pos = get_z_coordonate(c_data, i);
		y++;
		while (c_data[i] != 32 && c_data[i] != '\n' && c_data[i] != '\0')
			i++;
		while (c_data[i] == 32)
			i++;
		if (c_data[i] == '\n')
		{
			i++ ;
			y = 0;
			x++ ;
		}
		if (c_data[i] == '\0')
			return ;
	}
}

//set map position on window

t_map	set_up_map(int x_pos, int y_pos)
{
	t_map	map;
	int		i;

	i = 0;
	map.x_size = x_pos;
	map.y_size = y_pos;
	map.base = (WIDTH / map.y_size) / SCALE;
	if (map.base < 1)
		map.base = 1;
	map.dot = (t_dot **)malloc(sizeof(t_dot *) * map.x_size + 1);
	ft_bzero(map.dot, map.x_size);
	while (i <= map.x_size)
	{
		map.dot[i] = (t_dot *)malloc(sizeof(t_dot) * y_pos);
		i++;
	}
	map.dot[0][0].x_pos = WIDTH / 2;
	map.dot[0][0].y_pos = 20;
	return (map);
}
