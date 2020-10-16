/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkhwane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 09:49:48 by lmkhwane          #+#    #+#             */
/*   Updated: 2017/08/25 10:28:33 by lmkhwane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strcspn(const char *s1, const char *s2)
{
	char		*str1;
	char		*str2;

	if (!s1 || !s2)
		return (0);
	str1 = (char *)s1;
	while (*str1)
	{
		str2 = (char *)s2;
		while (*str2)
		{
			if (*str1 == *str2++)
				return (str1 - s1);
		}
		str1++;
	}
	return (str1 - s1);
}
