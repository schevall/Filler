/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_whitespace.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 13:14:56 by schevall          #+#    #+#             */
/*   Updated: 2017/03/17 13:07:42 by schevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		**ft_strsplit_whitespace(char const *s)
{
	char	**res;
	size_t	i;
	size_t	index;
	size_t	word_len;

	if (!s)
		return (NULL);
	i = 0;
	index = ft_count_word_whitespace(s);
	if (index == 0 || !(res = ft_memalloc(sizeof(char*) * (index + 1))))
		return (NULL);
	index = 0;
	while (s[i])
	{
		if (!ft_isspace(s[i]))
		{
			word_len = ft_word_len_whitespace(s, i);
			res[index] = ft_strsub(s, i, word_len);
			i = i + word_len;
			index++;
		}
		else
			i++;
	}
	return (res);
}
