/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 13:51:15 by schevall          #+#    #+#             */
/*   Updated: 2017/03/06 18:22:48 by schevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	**ft_strndup_tab(const char **src, int len)
{
	char	**cpy;
	int		i;

	cpy = (char**)ft_memalloc(sizeof(char*) * (len + 1));
	i = 0;
	while (src[i] && i < len)
	{
		cpy[i] = ft_strdup(src[i]);
		i++;
	}
	return (cpy);
}
