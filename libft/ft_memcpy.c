/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkhwane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 17:43:00 by lmkhwane          #+#    #+#             */
/*   Updated: 2017/07/24 12:36:52 by lmkhwane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*new_dst;
	char	*new_src;
	int		index;

	new_dst = (char*)dst;
	new_src = (char*)src;
	index = 0;
	while (n > 0)
	{
		new_dst[index] = new_src[index];
		index++;
		n--;
	}
	return (dst);
}
