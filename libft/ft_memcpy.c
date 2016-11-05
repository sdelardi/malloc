/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 13:23:38 by sdelardi          #+#    #+#             */
/*   Updated: 2015/11/23 14:33:30 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	size_t			i;
	unsigned char	*ch;
	unsigned char	*ch2;

	ch = (unsigned char *)str1;
	ch2 = (unsigned char *)str2;
	i = 0;
	while (i < n)
	{
		ch[i] = ch2[i];
		i++;
	}
	return (str1);
}
