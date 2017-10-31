/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 17:26:35 by schevall          #+#    #+#             */
/*   Updated: 2017/03/06 18:14:33 by schevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		*ft_memdup(const void *s, size_t n)
{
	void	*cpy;

	if (!(cpy = malloc(sizeof(unsigned char) * n)))
		return (NULL);
	ft_memcpy(cpy, s, n);
	return (cpy);
}
