/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkhwane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 11:15:10 by lmkhwane          #+#    #+#             */
/*   Updated: 2017/07/24 12:47:12 by lmkhwane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	int index;

	index = 0;
	if (s == NULL || f == NULL)
		return ;
	while (s != NULL && s[index] != '\0')
	{
		f(&s[index]);
		index++;
	}
}
