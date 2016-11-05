/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 13:29:56 by sdelardi          #+#    #+#             */
/*   Updated: 2015/11/25 14:50:18 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*chdest;
	unsigned char	*chsrc;

	chdest = (unsigned char *)dest;
	chsrc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		if (*chsrc == (unsigned char)c)
		{
			chdest++;
			return (chdest);
		}
		else
		{
			*chdest = *chsrc;
			chdest++;
			chsrc++;
		}
		i++;
	}
	return (NULL);
}
