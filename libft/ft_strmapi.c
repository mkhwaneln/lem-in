/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkhwane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 18:22:24 by lmkhwane          #+#    #+#             */
/*   Updated: 2017/07/24 15:22:42 by lmkhwane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	unsigned int	index;

	if (s == NULL || f == NULL)
		return (NULL);
	ret = (char *)ft_memalloc(sizeof(char) * ft_strlen(s) + 1);
	if (ret == NULL)
		return (NULL);
	index = 0;
	while (s[index] != '\0')
	{
		ret[index] = f(index, s[index]);
		index++;
	}
	return (ret);
}
