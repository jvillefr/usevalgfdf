/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:57:36 by jvillefr          #+#    #+#             */
/*   Updated: 2022/06/09 15:07:32 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdbool.h>
# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# define YELLOW 0X00FFFF00 
# define BUF_SIZE 4000
# define HEIGHT 1200
# define ESC_KEY 53
# define SCALE 50
# define WIDTH 2000

typedef struct s_vertex
{
	int		x_pos;
	int		y_pos;
	int		z_pos;
	int		color;
}	t_dot;

typedef struct s_map
{
	int		x_size;
	int		y_size;
	int		base;
	t_dot	**dot;
}	t_map;

typedef struct s_data
{
	void	*image;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_mlx
{
	void	*server;
	void	*window;
	t_data	*image;
}	t_mlx;

typedef struct s_bar
{
	int	x;
	int	y;
}	t_bar;

void	draw_line(t_dot start, t_dot end, t_data *img, t_map map);
void	my_mlx_pixel_put(t_data *img, int x, int y, int color);

void	add_x(t_dot *start, t_dot *end, int *d, int *p);
void	add_y(t_dot *start, t_dot *end, int *d, int *p);
void	gnl_memmove(char *dest, char *src, int len);
void	set_xy_coordonate(t_map *map, int x, int y);
void	fill_map_data(t_map *map, char *c_data);
int		get_z_coordonate(char *c_data, int i);
int		handle_key_input(int key, t_mlx *mlx);
char	*gnl_strcat(char *dest, char *src);
char	*clean_save(char *save, char *nl);
char	*clean_save(char *save, char *nl);
char	*clean_save(char *save, char *nl);

t_map	set_up_map(int x_pos, int y_pos);

int		same_pos(t_dot start, t_dot end);
char	*cut_line(char *save, char *nl);
char	*get_save(char *save, int fd);
void	render(t_map map, t_mlx *mlx);
char	*gnl_strchr(char *s, char c);
size_t	gnl_strlen(const char *s);
void	read_file(int fd, t_map map);
char	*get_next_line(int fd);
void	free_map(t_map *map);

t_map	file_data(int fd);
int		get_x(char *c_data);

int		get_y(char *c_data);
int		abs_of_val(int val);

#	endif
