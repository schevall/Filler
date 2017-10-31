/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 13:09:01 by schevall          #+#    #+#             */
/*   Updated: 2017/03/06 18:24:30 by schevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*dest;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen(s) - 1;
	while (ft_isspace(s[i]))
		i++;
	if (i == j + 1)
	{
		dest = ft_strnew(1);
		dest[0] = '\0';
		return (dest);
	}
	while (ft_isspace(s[j]))
		j--;
	return (ft_strsub(s, i, j - i + 1));
}
