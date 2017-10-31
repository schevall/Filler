/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 11:03:24 by schevall          #+#    #+#             */
/*   Updated: 2017/03/13 15:03:27 by schevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strdup_free(char *src)
{
	size_t	len;
	char	*dest;
	int		i;

	len = ft_strlen(src);
	if (!(dest = (char*)ft_memalloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	ft_strdel(&src);
	return (dest);
}
