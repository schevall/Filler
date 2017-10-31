/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 13:03:01 by schevall          #+#    #+#             */
/*   Updated: 2017/03/06 18:14:52 by schevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void				*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	a;
	unsigned char	*mem;

	i = 0;
	a = (unsigned char)c;
	mem = (unsigned char *)s;
	while (i < n)
	{
		mem[i] = a;
		i++;
	}
	return (mem);
}
