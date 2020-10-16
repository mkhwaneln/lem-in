/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkhwane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 10:17:01 by lmkhwane          #+#    #+#             */
/*   Updated: 2017/07/24 12:43:01 by lmkhwane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t		i;
	size_t		len;
	char		*dst;
	const char	*source;

	i = n;
	dst = dest;
	source = src;
	while (i-- != 0 && *dst != '\0')
		dst++;
	len = dst - dest;
	i = n - len;
	if (i == 0)
		return (len + ft_strlen(source));
	while (*source != '\0')
	{
		if (i != 1)
		{
			*dst++ = *source;
			i--;
		}
		source++;
	}
	*dst = '\0';
	return (len + (source - src));
}
