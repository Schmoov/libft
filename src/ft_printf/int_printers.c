/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_printers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:07:25 by parden            #+#    #+#             */
/*   Updated: 2024/06/07 12:23:39 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	c_printer(t_token *tok, int n)
{
	int	count;

	count = 1;
	while (!tok->minus_flag && tok->width > 1)
	{
		ft_putchar_fd(' ', 1);
		tok->width--;
		count++;
	}
	ft_putchar_fd((unsigned char)n, 1);
	while (tok->minus_flag && tok->width > 1)
	{
		ft_putchar_fd(' ', 1);
		tok->width--;
		count++;
	}
	return (count);
}

int	d_printer(t_token *tok, int n)
{
	char	*toprint;
	int		ret_value;

	if (n < 0)
		tok->sign = '-';
	if (!n && tok->has_prec && !tok->precision)
		toprint = ft_strdup("");
	else
		toprint = itoa_base(n, BASE10, true);
	add_precision_zeroes(&toprint, tok);
	add_width_zeroes(&toprint, tok, !!tok->sign);
	add_sign(&toprint, tok);
	add_width_blanks(&toprint, tok);
	if (!toprint)
		return (-1);
	ret_value = ft_strlen(toprint);
	ft_putstr_fd(toprint, 1);
	free(toprint);
	return (ret_value);
}

int	u_printer(t_token *tok, int n)
{
	char	*toprint;
	int		ret_value;

	if (!n && tok->has_prec && !tok->precision)
		toprint = ft_strdup("");
	else
		toprint = itoa_base(n, BASE10, false);
	add_precision_zeroes(&toprint, tok);
	add_width_zeroes(&toprint, tok, 0);
	add_width_blanks(&toprint, tok);
	if (!toprint)
		return (-1);
	ret_value = ft_strlen(toprint);
	ft_putstr_fd(toprint, 1);
	free(toprint);
	return (ret_value);
}

int	xlo_printer(t_token *tok, int n)
{
	char	*toprint;
	int		ret_value;

	if (!n && tok->has_prec && !tok->precision)
		toprint = ft_strdup("");
	else
		toprint = itoa_base(n, LOBASE16, false);
	add_precision_zeroes(&toprint, tok);
	add_width_zeroes(&toprint, tok, 2 * tok->prefix * !!n);
	if (n)
		add_base_prefix(&toprint, tok, "0x");
	add_width_blanks(&toprint, tok);
	if (!toprint)
		return (-1);
	ret_value = ft_strlen(toprint);
	ft_putstr_fd(toprint, 1);
	free(toprint);
	return (ret_value);
}

int	xup_printer(t_token *tok, int n)
{
	char	*toprint;
	int		ret_value;

	if (!n && tok->has_prec && !tok->precision)
		toprint = ft_strdup("");
	else
		toprint = itoa_base(n, UPBASE16, false);
	add_precision_zeroes(&toprint, tok);
	add_width_zeroes(&toprint, tok, 2 * tok->prefix * !!n);
	if (n)
		add_base_prefix(&toprint, tok, "0X");
	add_width_blanks(&toprint, tok);
	if (!toprint)
		return (-1);
	ret_value = ft_strlen(toprint);
	ft_putstr_fd(toprint, 1);
	free(toprint);
	return (ret_value);
}
