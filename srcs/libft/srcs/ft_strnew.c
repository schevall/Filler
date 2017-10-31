/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 13:07:45 by schevall          #+#    #+#             */
/*   Updated: 2017/03/06 18:23:07 by schevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnew(size_t n)
{
	char *str;

	if (!(str = malloc(sizeof(char) * (n + 1))))
		return (NULL);
	if (str)
	{
		ft_bzero(str, n + 1);
		return (str);
	}
	else
		return (NULL);
}
