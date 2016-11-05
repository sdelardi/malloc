/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 13:53:55 by sdelardi          #+#    #+#             */
/*   Updated: 2015/11/24 16:08:12 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*ch;
	unsigned char	*ch2;

	ch = (unsigned char *)dst;
	ch2 = (unsigned char *)src;
	if (dst < src)
	{
		i = 0;
		while (i < len)
		{
			ch[i] = ch2[i];
			i++;
		}
	}
	else
	{
		i = len - 1;
		while ((int)i >= 0)
		{
			ch[i] = ch2[i];
			i--;
		}
	}
	return (dst);
}
