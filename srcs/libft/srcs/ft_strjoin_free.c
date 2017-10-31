/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 16:39:19 by schevall          #+#    #+#             */
/*   Updated: 2017/03/06 18:20:14 by schevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin_free(char *s1, int i, char *s2, int j)
{
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	if (!(new = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	ft_strcat(new, s1);
	ft_strcat(new, s2);
	if (i == 1)
		ft_strdel(&s1);
	if (j == 1)
		ft_strdel(&s2);
	return (new);
}
