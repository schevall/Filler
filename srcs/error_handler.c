/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schevall <schevall@4student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 08:00:00 by schevall          #+#    #+#             */
/*   Updated: 2017/10/25 08:00:00 by schevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/filler.h"

void	error_handling(char *reason)
{
	ft_printf_fd(2, "%s", reason);
	exit(1);
}
