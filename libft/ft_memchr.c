/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 13:55:29 by sdelardi          #+#    #+#             */
/*   Updated: 2015/11/25 14:29:53 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char *ch;

	ch = (unsigned char *)str;
	while (n)
	{
		if (*ch == (unsigned char)c)
			return (ch);
		ch++;
		n--;
	}
	return (NULL);
}
