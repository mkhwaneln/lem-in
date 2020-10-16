/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkhwane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 18:23:51 by lmkhwane          #+#    #+#             */
/*   Updated: 2017/07/24 12:43:45 by lmkhwane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t len;
	size_t index;

	len = ft_strlen(dest);
	index = 0;
	while (src[index] && n > 0)
	{
		dest[index + len] = src[index];
		index++;
		n--;
	}
	dest[index + len] = '\0';
	return (dest);
}
