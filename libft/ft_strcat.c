/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkhwane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 18:00:53 by lmkhwane          #+#    #+#             */
/*   Updated: 2017/07/24 12:40:59 by lmkhwane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	size_t len;
	size_t index;

	len = ft_strlen(dest);
	index = 0;
	while (src[index] != '\0')
	{
		dest[len + index] = src[index];
		index++;
	}
	dest[len + index] = '\0';
	return (dest);
}
