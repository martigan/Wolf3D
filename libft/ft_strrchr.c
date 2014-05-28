/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspail <mgaspail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 12:46:43 by mgaspail          #+#    #+#             */
/*   Updated: 2014/04/26 14:28:10 by mgaspail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char		*ft_strrchr(const char *str, int c)
{
	char	*tmp;

	tmp = NULL;
	while (*str)
	{
		if (*str == (char)c)
			tmp = (char*)str;
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (tmp);
}
