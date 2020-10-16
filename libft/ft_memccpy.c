/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkhwane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 17:32:36 by lmkhwane          #+#    #+#             */
/*   Updated: 2017/07/24 12:36:20 by lmkhwane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*c_dest;
	char	*c_src;
	size_t	index;

	c_dest = (char *)dest;
	c_src = (char *)src;
	index = 0;
	while (index < n)
	{
		c_dest[index] = c_src[index];
		if (c_src[index] == c)
			return (c_dest + index + 1);
		index++;
	}
	return (NULL);
}
