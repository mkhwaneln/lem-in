/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkhwane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 18:26:55 by lmkhwane          #+#    #+#             */
/*   Updated: 2017/07/24 12:45:16 by lmkhwane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t index;
	size_t len;

	len = ft_strlen(s2);
	index = 0;
	if (len == 0)
		return ((char *)s1);
	while ((s1[index] != '\0') && len <= n)
	{
		if (ft_memcmp(s1 + index, s2, len) == 0)
			return ((char *)(s1 + index));
		index++;
		n--;
	}
	return (NULL);
}
