/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkhwane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 11:15:56 by lmkhwane          #+#    #+#             */
/*   Updated: 2017/07/24 12:42:21 by lmkhwane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int		index;

	index = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (s1[index] != '\0' && s1[index] == s2[index])
	{
		index++;
	}
	if (s1[index] == s2[index])
		return (1);
	else
		return (0);
}
