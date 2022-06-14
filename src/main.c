/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:02:19 by jvillefr          #+#    #+#             */
/*   Updated: 2022/06/13 08:59:52 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../include/fdf.h"

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH)
		return ;
	if (y < 0 || y >= HEIGHT)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(int *)dst = color;
}

t_data	*init_img(t_mlx *mlx)
{
	t_data	*img;

	img = ft_calloc(1, sizeof(t_data));
	img->image = mlx_new_image(mlx->server, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->image, &img->bits_per_pixel, \
		&img->line_length, &img->endian);
	return (img);
}

t_map	file_data(int fd)
{
	t_map	map;
	char	*buffer;
	char	*c_data;

	buffer = get_next_line(fd);
	c_data = NULL;
	while (buffer != NULL)
	{
		c_data = ft_strjoin(c_data, buffer);
		free (buffer);
		if (!map.y_size)
			map.y_size = get_y(c_data);
		buffer = get_next_line(fd);
		if (get_y(buffer) != map.y_size && buffer != NULL)
		{
			free (buffer);
			exit(0);
		}
	}
	map = set_up_map(get_x(c_data), get_y(c_data));
	fill_map_data(&map, c_data);
	free (buffer);
	free (c_data);
	return (map);
}

bool	is_fdf_file(char *path)
{
	while (*path != '\0')
	{
		if (*path == '.' && *(path + 4) == '\0')
			return (true);
		path++;
	}
	return (false);
}

int	main(int argc, char **argv)
{
	t_map	map;
	t_mlx	mlx;
	int		fd;

	if (argc != 2)
		return (0);
	if (!(is_fdf_file(argv[1])))
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd< 3)
		return (0);
	map = file_data(fd);
	close(fd);
	mlx.server = mlx_init();
	mlx.window = mlx_new_window(mlx.server, WIDTH, HEIGHT, "fdf");
	mlx.image = init_img(&mlx);
	render(map, &mlx);
	free_map(&map);
	mlx_hook(mlx.window, 2, 3, &handle_key_input, &mlx);
	mlx_hook(mlx.window, 17, 0, &handle_key_input, &mlx);
	mlx_loop(mlx.server);
	return (0);
}
