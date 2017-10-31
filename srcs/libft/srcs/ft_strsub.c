/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 13:08:41 by schevall          #+#    #+#             */
/*   Updated: 2017/03/06 18:24:20 by schevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *cpy;

	if (!(cpy = ft_strnew(len)) || !s)
		return (NULL);
	ft_strncpy(cpy, s + start, len);
	cpy[len] = '\0';
	return (cpy);
}
