/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 19:08:12 by sdelardi          #+#    #+#             */
/*   Updated: 2015/11/24 20:46:24 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int i;
	int j;
	int size_dst;

	i = 0;
	j = 0;
	while (size > 0 && dst[i] != '\0')
	{
		i++;
		size--;
	}
	size_dst = i;
	if (size == 0 && dst[i] != '\0')
		return (i + ft_strlen(src));
	while ((size - 1) != 0 && src[j] != '\0')
	{
		dst[i] = src[j];
		i++;
		j++;
		size--;
	}
	dst[i] = '\0';
	return (size_dst + ft_strlen(src));
}
