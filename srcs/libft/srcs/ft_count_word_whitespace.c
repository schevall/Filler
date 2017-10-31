/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word_whitespace.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 13:16:02 by schevall          #+#    #+#             */
/*   Updated: 2017/03/13 15:03:05 by schevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t		ft_count_word_whitespace(char const *s)
{
	size_t	word;
	int		i;

	word = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && ft_isspace(s[i]))
			i++;
		if (s[i] && !ft_isspace(s[i]))
		{
			word++;
			while (s[i] && !ft_isspace(s[i]))
				i++;
		}
	}
	return (word);
}
