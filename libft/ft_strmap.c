/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkhwane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 18:21:46 by lmkhwane          #+#    #+#             */
/*   Updated: 2017/07/24 12:43:24 by lmkhwane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		index;
	char	*ret;

	index = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	ret = (char *)ft_memalloc(ft_strlen(s) + 1);
	if (ret == NULL)
		return (NULL);
	while (s[index] != '\0')
	{
		ret[index] = f(s[index]);
		index++;
	}
	return (ret);
}
