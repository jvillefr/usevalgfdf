/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 17:41:17 by jvillefr          #+#    #+#             */
/*   Updated: 2021/05/30 18:03:45 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_invstr(char *str, int size)
{
	int	temp;
	int	start;
	int	end;

	start = 0;
	end = size - 1;
	if (str[start] == '-')
		start++;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
	return (str);
}

static int	ft_intlen(int n)
{
	int	len;

	len = 1;
	if (n >= 0)
		n *= -1;
	else
		len++;
	while (n <= -10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_ifzero(char *str)
{
	int	index;

	index = 0;
	str[index++] = '0';
	str[index] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			i;
	long		nb;
	int			len;

	i = 0;
	len = ft_intlen(n);
	nb = n;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	if (nb == 0)
		return (ft_ifzero(str));
	if (nb < 0)
	{
		nb = -nb;
		str[i++] = '-';
	}
	while (nb != 0)
	{
		str[i++] = (nb % 10) + '0';
		nb /= 10;
	}
	str[i] = '\0';
	return (ft_invstr(str, ft_strlen(str)));
}
