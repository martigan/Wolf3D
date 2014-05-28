/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspail <mgaspail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:44:18 by mgaspail          #+#    #+#             */
/*   Updated: 2013/12/01 17:50:39 by mgaspail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	const char	*str;
	char		*dst;

	str = src;
	dst = dest;
	while (n-- > 0)
	{
		if ((*dst++ = *str++) == c)
			return (dst);
	}
	return (NULL);
}
