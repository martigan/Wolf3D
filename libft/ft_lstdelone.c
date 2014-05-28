/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspail <mgaspail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 17:12:42 by mgaspail          #+#    #+#             */
/*   Updated: 2013/11/30 12:45:29 by mgaspail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	del(alst->content, alst->size_content);
	free(alst->content);
	alst->content = NULL;
	free(alst->size_content);
	alst->size_content = NULL;
	free(*alst);
	*alst = NULL;
}
