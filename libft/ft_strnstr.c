/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspail <mgaspail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 13:15:51 by mgaspail          #+#    #+#             */
/*   Updated: 2013/12/30 20:58:12 by mgaspail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <unistd.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t			size_s2;

	if (!*s2)
		return ((char *)s1);
	size_s2 = ft_strlen(s2);
	while (*s1 != '\0' && n >= size_s2)
	{
		if (ft_memcmp(s1, s2, size_s2) == 0 && size_s2 <= n)
			return ((char *)s1);
		s1++;
		n--;
	}
	return (NULL);
}
