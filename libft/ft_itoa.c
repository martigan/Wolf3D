/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspail <mgaspail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 11:05:13 by mgaspail          #+#    #+#             */
/*   Updated: 2014/04/26 14:29:03 by mgaspail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <string.h>

static void		ft_nbr_str(int n, char *dest)
{
	if (n >= 0)
	{
		if (n >= 10)
		{
			ft_nbr_str(n / 10, dest);
			ft_nbr_str(n % 10, dest);
		}
		else
			dest[ft_strlen(dest)] = n + '0';
	}
	else
	{
		dest[0] = '-';
		ft_nbr_str(-n, dest);
	}
}

char			*ft_itoa(int nbr)
{
	char	*dest;

	dest = (char *)malloc(sizeof(char) * 13);
	if (!dest)
		return (NULL);
	ft_bzero(dest, 13);
	if (nbr == -2147483648)
	{
		ft_nbr_str(nbr + 1, dest);
		dest[10] = '8';
	}
	else
		ft_nbr_str(nbr, dest);
	return (dest);
}
