/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkhwane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 08:21:14 by lmkhwane          #+#    #+#             */
/*   Updated: 2017/07/28 09:06:48 by lmkhwane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strpbrk(const char *s1, const char *s2)
{
	char	*str1;
	char	*str2;
	int		index;
	int		index2;

	if (!s1 || !s2)
		return (NULL);
	index = 0;
	str1 = (char *)s1;
	str2 = (char *)s2;
	while (str1[index] != '\0')
	{
		index2 = 0;
		while (str2[index2] != '\0')
		{
			if (str1[index] == str2[index2])
				return ((char *)&str1[index]);
			index2++;
		}
		index++;
	}
	return (NULL);
}
