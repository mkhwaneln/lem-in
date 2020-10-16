/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkhwane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 12:51:26 by lmkhwane          #+#    #+#             */
/*   Updated: 2017/07/24 15:04:00 by lmkhwane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*mylist;

	if (!(mylist = (t_list *)ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		if (!(mylist->content = (t_list *)ft_memalloc(sizeof(t_list))))
			return (NULL);
		ft_memcpy(mylist->content, content, content_size);
		mylist->content_size = content_size;
	}
	else
	{
		mylist->content = NULL;
		mylist->content_size = 0;
	}
	mylist->next = NULL;
	return (mylist);
}
