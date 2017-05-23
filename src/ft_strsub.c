/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 13:08:36 by sdelardi          #+#    #+#             */
/*   Updated: 2015/12/11 15:52:18 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*ptr;
	unsigned int	i;

	ptr = ft_strnew(len);
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
