/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 17:05:33 by jvillefr          #+#    #+#             */
/*   Updated: 2021/05/30 17:29:21 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_checkset(const char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start;
	size_t	end;
	size_t	index;

	index = 0;
	start = 0;
	if (!s1)
		return (NULL);
	end = ft_strlen(s1);
	while (s1[start] && ft_checkset(s1[start], set) == 1)
		start++;
	while (end > start && ft_checkset(s1[end - 1], set) == 1)
		end--;
	str = malloc(sizeof(*s1) * (end - start) + 1);
	if (!str)
		return (NULL);
	while (start < end)
	{
		str[index] = s1[start];
		start++;
		index++;
	}
	str[index] = '\0';
	return (str);
}
