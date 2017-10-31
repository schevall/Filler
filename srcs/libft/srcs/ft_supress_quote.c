/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_supress_quote.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 12:43:13 by schevall          #+#    #+#             */
/*   Updated: 2017/03/20 15:17:51 by schevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_supress_quote(char **line)
{
	int		len;
	int		i;
	int		j;
	char	*new;

	if (!ft_strchr(*line, 39) && !ft_strchr(*line, 34))
		return ;
	i = 0;
	len = ft_strlen(*line);
	j = 0;
	new = (char*)ft_memalloc(len + 1);
	while ((*line)[i])
	{
		if ((*line)[i] != 39 && (*line)[i] != 34)
		{
			new[j] = (*line)[i];
			j++;
		}
		i++;
	}
	ft_bzero(*line, ft_strlen(*line));
	*line = ft_strcpy(*line, new);
	ft_strdel(&new);
}
