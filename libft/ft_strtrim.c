/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkhwane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 11:33:56 by lmkhwane          #+#    #+#             */
/*   Updated: 2017/07/24 12:46:30 by lmkhwane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_trim(char *s)
{
	size_t			i;
	size_t			space;
	size_t			len;

	len = ft_strlen(s);
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	space = i;
	if (s[i] != '\0')
	{
		i = len - 1;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		{
			i--;
			space++;
		}
	}
	return (len - space);
}

char				*ft_strtrim(char const *s)
{
	char			*str;
	size_t			i;
	size_t			n;
	size_t			trim;

	i = 0;
	n = 0;
	if (!s)
		return (NULL);
	trim = ft_trim((char *)s);
	str = (char *)malloc(sizeof(*str) * (trim + 1));
	if (str == NULL)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (n < trim)
	{
		str[n] = s[i];
		n++;
		i++;
	}
	str[n] = '\0';
	return (str);
}
