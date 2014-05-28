/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspail <mgaspail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:57:32 by mgaspail          #+#    #+#             */
/*   Updated: 2014/04/26 14:26:20 by mgaspail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <string.h>

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	str = ft_memalloc(ft_strlen((char*)s));
	if (!str)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	str = ft_strcpy(str, s + i);
	len = ft_strlen(str);
	i = 1;
	if (len - i > 0)
	{
		while (str[len - i] == ' ' || str[len - i] == '\n'
				|| str[len - i] == '\t')
		{
			str[len - i] = '\0';
			i++;
		}
	}
	return (str);
}
