/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_len_whitespace.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 13:24:10 by schevall          #+#    #+#             */
/*   Updated: 2017/03/13 13:27:18 by schevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t		ft_word_len_whitespace(const char *s, size_t i)
{
	size_t len;

	len = 0;
	while (s[i] && !ft_isspace(s[i]))
	{
		len++;
		i++;
	}
	return (len);
}
