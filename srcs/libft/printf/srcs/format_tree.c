/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 16:26:26 by schevall          #+#    #+#             */
/*   Updated: 2017/03/06 18:42:37 by schevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	create_str_arg(char **str_arg, t_param *params)
{
	if (params->width != -1 && params->width)
		*str_arg = ft_strcnew(params->size_tot, ' ');
	else if (params->prec > 0 && params->prec > params->width)
		*str_arg = ft_strcnew(params->size_tot, '0');
	else
		*str_arg = ft_strnew(params->size_tot);
}

int		format_tree(char **s, va_list ap, t_param *p)
{
	char *formated_arg;
	char *tmp;

	formated_arg = NULL;
	tmp = *s;
	if (is_signed_conv(p->conv))
		formated_arg = format_signed(formated_arg, ap, p);
	else if (is_unsigned_conv(p->conv))
		formated_arg = format_unsign(formated_arg, ap, p);
	else if (p->conv == 's' && p->length.l != 1)
		formated_arg = format_string(formated_arg, ap, p);
	else if (p->conv == 'C' || (p->conv == 'c' && p->length.l > 0))
		formated_arg = format_wchar(formated_arg, ap, p);
	else if (p->conv == 'S' || (p->conv == 's' && p->length.l))
		formated_arg = format_wstring(formated_arg, ap, p);
	else
		formated_arg = format_char(formated_arg, ap, p);
	if (p->size_tot != -1)
		*s = ft_strnjoin(*s, p->size_s_tot, formated_arg, p->size_tot);
	ft_strdel(&tmp);
	ft_strdel(&formated_arg);
	return (p->size_tot);
}
