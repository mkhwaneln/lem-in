/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkhwane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 12:57:47 by lmkhwane          #+#    #+#             */
/*   Updated: 2017/07/24 15:35:23 by lmkhwane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*find;
	t_list		*found;

	if (!alst || !*alst)
		return ;
	found = *alst;
	while (found)
	{
		find = found->next;
		ft_lstdelone(&found, del);
		found = find;
	}
	*alst = NULL;
}
