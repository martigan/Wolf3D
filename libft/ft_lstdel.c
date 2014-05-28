/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspail <mgaspail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 17:24:49 by mgaspail          #+#    #+#             */
/*   Updated: 2013/11/29 19:00:24 by mgaspail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (alst->next == NULL)
		ft_lstdelone(alst->content, alst->content_size);
	else
	{
		del(alst->content, alst->content_size);
		free(alst->content);
		alst->content = NULL;
		free(alst->content_size);
		alst->content_size = NULL;
		ft_lstdel(alst->next, del);
		alst->next = NULL;
	}
}
