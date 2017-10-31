/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 14:39:58 by schevall          #+#    #+#             */
/*   Updated: 2017/03/08 15:15:39 by schevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strndup(const char *src, size_t n)
{
	char	*dest;

	if (!(dest = (char*)ft_memalloc(sizeof(char) * (n + 1))))
		return (NULL);
	return (ft_strncpy(dest, src, n));
}
