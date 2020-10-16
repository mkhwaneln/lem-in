/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkhwane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 18:28:10 by lmkhwane          #+#    #+#             */
/*   Updated: 2017/07/24 12:45:53 by lmkhwane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int index;
	int index1;
	int size_sub;

	index = 0;
	index1 = 0;
	size_sub = ft_strlen(to_find);
	if (size_sub == 0)
		return ((char *)str);
	while (str[index] != '\0')
	{
		while (str[index + index1] == to_find[index1])
		{
			if (index1 == size_sub - 1)
				return ((char *)(str + index));
			index1++;
		}
		index1 = 0;
		index++;
	}
	return (NULL);
}
