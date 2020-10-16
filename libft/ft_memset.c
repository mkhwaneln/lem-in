/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkhwane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 17:45:17 by lmkhwane          #+#    #+#             */
/*   Updated: 2017/07/24 12:37:34 by lmkhwane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*buf;
	size_t			index;

	buf = (unsigned char *)b;
	index = 0;
	while (len > 0)
	{
		buf[index] = c;
		index++;
		len--;
	}
	return ((void *)buf);
}
