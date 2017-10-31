/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 14:30:41 by schevall          #+#    #+#             */
/*   Updated: 2017/03/06 18:19:16 by schevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	**ft_strdup_tab(const char **src)
{
	char	**cpy;
	int		line;
	int		i;

	line = ft_tablen(src);
	cpy = (char**)ft_memalloc(sizeof(char*) * (line + 1));
	i = 0;
	while (src[i])
	{
		cpy[i] = ft_strdup(src[i]);
		i++;
	}
	return (cpy);
}
