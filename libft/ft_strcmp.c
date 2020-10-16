/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkhwane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 18:07:28 by lmkhwane          #+#    #+#             */
/*   Updated: 2017/07/24 12:41:33 by lmkhwane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int index;

	index = 0;
	if (s1 && s2)
	{
		while (s1[index] == s2[index] && s1[index] != '\0')
		{
			index++;
		}
		return ((const unsigned char)s1[index] - (const unsigned char)s2[index]);
	}
	return (1);
}
