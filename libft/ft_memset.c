/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 10:47:04 by sdelardi          #+#    #+#             */
/*   Updated: 2015/11/23 14:33:11 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*ch;

	ch = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		ch[i] = (unsigned char)c;
		i++;
	}
	return (str);
}
