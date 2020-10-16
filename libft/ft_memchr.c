/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkhwane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 17:39:41 by lmkhwane          #+#    #+#             */
/*   Updated: 2017/07/24 12:36:32 by lmkhwane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *new_s;
	unsigned char new_c;

	new_s = (unsigned char *)s;
	new_c = (unsigned char)c;
	while (n-- > 0)
	{
		if (*new_s == new_c)
			return (new_s);
		new_s++;
	}
	return (NULL);
}
