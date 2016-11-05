/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:01:38 by sdelardi          #+#    #+#             */
/*   Updated: 2016/01/11 11:00:16 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*ptr;
	unsigned int	i;

	ptr = ft_strnew(len + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	s += start;
	while (len)
	{
		ptr[i] = s[i];
		len--;
		i++;
	}
	return (ptr);
}
