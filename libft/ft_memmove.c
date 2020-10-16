/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkhwane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 17:44:39 by lmkhwane          #+#    #+#             */
/*   Updated: 2017/07/24 12:37:23 by lmkhwane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*temp;
	size_t	index;

	temp = (char *)ft_memalloc(n);
	index = 0;
	if (temp != NULL)
	{
		ft_memcpy(temp, src, n);
		ft_memcpy(dest, temp, n);
	}
	return (dest);
}
