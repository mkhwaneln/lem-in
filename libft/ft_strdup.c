/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkhwane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 13:35:41 by lmkhwane          #+#    #+#             */
/*   Updated: 2017/07/24 12:42:09 by lmkhwane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *dup;

	dup = (char *)ft_memalloc(ft_strlen(s1) + 1);
	if (!dup)
		return (NULL);
	dup = ft_strcpy(dup, s1);
	return (dup);
}
