/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkhwane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 17:57:14 by lmkhwane          #+#    #+#             */
/*   Updated: 2017/07/24 12:40:21 by lmkhwane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *str, int fd)
{
	int counter;

	if (!str)
		return ;
	counter = 0;
	while (str[counter] != '\0')
	{
		ft_putchar_fd(str[counter], fd);
		counter++;
	}
}
