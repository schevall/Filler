/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 11:47:58 by schevall          #+#    #+#             */
/*   Updated: 2017/03/06 18:18:25 by schevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strcnew(size_t n, int c)
{
	char *str;

	if (!(str = malloc(sizeof(char) * (n + 1))))
		return (NULL);
	ft_memset(str, c, n);
	str[n] = '\0';
	return (str);
}
