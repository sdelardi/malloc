/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 21:06:49 by sdelardi          #+#    #+#             */
/*   Updated: 2015/11/25 14:52:42 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;

	str = (char *)s;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			str = ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		str = ((char *)s + i);
	if (str != s || s[0] == (char)c)
		return (str);
	else
		return (NULL);
}
