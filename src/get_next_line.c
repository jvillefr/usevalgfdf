/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:29:34 by jvillefr          #+#    #+#             */
/*   Updated: 2022/06/09 12:31:17 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../include/fdf.h"

char	*clean_save(char *save, char *nl)
{
	char	*temp;

	temp = malloc(sizeof(char *) * ft_strlen(nl) + 1);
	gnl_memmove(temp, nl, ft_strlen(nl));
	free (save);
	save = NULL;
	save = malloc(sizeof(char *) * ft_strlen(temp) + 1);
	gnl_memmove(save, temp, ft_strlen(temp));
	free (temp);
	return (save);
}

char	*cut_line(char *save, char *nl)
{
	char	*line;
	int		n_len;

	n_len = ft_strlen(save) - ft_strlen(nl);
	line = malloc(sizeof(char *) * n_len + 1);
	gnl_memmove(line, save, n_len);
	return (line);
}

char	*get_save(char *save, int fd)
{
	char	*buffer;
	int		bytes;

	bytes = 1;
	buffer = malloc(sizeof(char *) * BUF_SIZE + 1);
	while (bytes > 0 && !(gnl_strchr(save, '\n')))
	{
		bytes = read(fd, buffer, BUF_SIZE);
		if (bytes < 1)
		{
			free(buffer);
			return (save);
		}
		buffer[bytes] = '\0';
		save = gnl_strcat(save, buffer);
	}
	free (buffer);
	return (save);
}

char	*get_next_line(int fd)
{
	static char		*save;
	char			*nl;
	char			*line;

	nl = NULL;
	save = get_save(save, fd);
	nl = gnl_strchr(save, '\n');
	if (!nl || *(nl + 1) == '\0')
	{
		if (save)
		{
			line = malloc(sizeof(char *) * ft_strlen(save) + 1);
			gnl_memmove(line, save, ft_strlen(save));
			free (save);
			save = NULL;
			return (line);
		}
		return (NULL);
	}
	nl += 1;
	line = cut_line(save, nl);
	save = clean_save(save, nl);
	return (line);
}
