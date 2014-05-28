/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspail <mgaspail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 02:10:18 by mgaspail          #+#    #+#             */
/*   Updated: 2013/12/02 04:43:14 by mgaspail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"
#define BUFF_SIZE 4096

int		ft_read_file(int fd, char **str)
{
	ssize_t	ret;
	char	buff[BUFF_SIZE + 1];
	char	*tmp;

	*str = (char *)malloc(sizeof(char) * 1);
	**str = '\0';
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = ft_strjoin(*str, buff);
		free(*str);
		*str = tmp;
	}
	if (ret == -1)
		return (-1);
	return (0);
}
