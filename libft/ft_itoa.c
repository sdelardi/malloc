/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 09:21:01 by sdelardi          #+#    #+#             */
/*   Updated: 2016/11/05 09:24:03 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_size_str(int n)
{
	int count;

	count = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char			*ft_itoa(int n)
{
	int		size;
	char	*ptr;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = ft_size_str(n);
	if ((ptr = ft_strnew(size)) == NULL)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		ptr[0] = '-';
	}
	if (n == 0)
		ptr[0] = '0';
	while (n)
	{
		ptr[size - 1] = n % 10 + '0';
		n /= 10;
		size--;
	}
	return (ptr);
}
