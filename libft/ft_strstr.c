/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspail <mgaspail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 12:57:25 by mgaspail          #+#    #+#             */
/*   Updated: 2014/04/26 14:26:52 by mgaspail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char		*ft_strstr(const char *s1, const char *s2)
{
	size_t	len;

	if (!s2)
		return ((char*)s1);
	if (!s1)
		return (NULL);
	len = ft_strlen(s2);
	if (len == 0)
		return ((char*)s1);
	while (*s1 != '\0')
	{
		if (*s1 == *s2 && ft_strncmp(s1, s2, len) == 0)
			return ((char*)s1);
		s1++;
	}
	return (NULL);
}
