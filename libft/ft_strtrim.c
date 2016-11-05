/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:23:05 by sdelardi          #+#    #+#             */
/*   Updated: 2015/11/26 15:32:34 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*str;
	int		k;

	i = 0;
	j = 0;
	while (s[j] != '\0' && (s[j] == ' ' || s[j] == '\n' || s[j] == '\t'))
		j++;
	i = ft_strlen(s) - 1;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && i > j)
		i--;
	str = (char *)malloc(sizeof(char) * (i - j + 1));
	if (str == NULL || j == 0)
		return (str == NULL ? NULL : (char *)s);
	k = 0;
	while (j <= i)
	{
		str[k] = s[j];
		j++;
		k++;
	}
	str[k] = '\0';
	return (str);
}
