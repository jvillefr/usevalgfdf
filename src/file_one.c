/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:59:00 by jvillefr          #+#    #+#             */
/*   Updated: 2022/06/09 13:59:46 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../include/fdf.h"

int	handle_key_input(int key, t_mlx *mlx)
{
	if (key == ESC_KEY || key == 17)
	{
		free (mlx->image);
		mlx_destroy_image(mlx->server, mlx->image->image);
		mlx_destroy_window(mlx->server, mlx->window);
	}
	exit (0);
}

char	*gnl_strchr(char *s, char c)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			if (s[i] == c)
				return (s + i);
			i++;
		}
	}
	return (NULL);
}

size_t	gnl_strlen(const char *s)
{
	int	len;

	len = 0;
	if (s)
		while (*s++)
			len++;
	return (len);
}

void	gnl_memmove(char *dest, char *src, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
			i++;
	}
	dest[len] = '\0';
}

char	*gnl_strcat(char *dest, char *src)
{
	char	*temp;
	int		n_len;

	if (!dest)
	{
		dest = malloc(sizeof(char *) * gnl_strlen(src));
		gnl_memmove(dest, src, gnl_strlen(src));
		return (dest);
	}
	n_len = gnl_strlen(dest) + gnl_strlen(src);
	temp = malloc(sizeof(char *) * n_len + 1);
	gnl_memmove(temp, dest, gnl_strlen(dest));
	gnl_memmove(temp + gnl_strlen(dest), src, gnl_strlen(src));
	free (dest);
	dest = malloc(sizeof(char *) * n_len + 1);
	gnl_memmove(dest, temp, n_len);
	free (temp);
	return (dest);
}
