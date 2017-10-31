/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 13:04:48 by schevall          #+#    #+#             */
/*   Updated: 2017/03/06 18:19:06 by schevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strdup(const char *src)
{
	size_t	len;
	char	*dest;

	len = ft_strlen(src);
	if (!(dest = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	return (ft_strcpy(dest, src));
}
