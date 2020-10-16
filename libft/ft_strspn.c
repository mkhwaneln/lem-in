/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkhwane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 09:16:04 by lmkhwane          #+#    #+#             */
/*   Updated: 2017/07/28 10:11:24 by lmkhwane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strspn(const char *s1, const char *s2)
{
	char		*str1;
	char		*str2;
	size_t		count;
	int			index;
	int			index2;

	if (!s1 || !s2)
		return (0);
	str1 = (char *)s1;
	str2 = (char *)s2;
	count = 0;
	index = 0;
	while (str1[index] != '\0')
	{
		index2 = 0;
		while (str2[index2] != '\0')
		{
			if (str1[index] == str2[index2])
				count++;
			index2++;
		}
		index++;
	}
	return (count);
}
