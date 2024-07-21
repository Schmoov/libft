/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:07:25 by parden            #+#    #+#             */
/*   Updated: 2024/06/04 18:00:19 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	add_width_blanks(char **toprint, t_token *tok)
{
	if (!*toprint)
		return ;
	if (!tok->zero_flag && tok->width >= 0
		&& (size_t)tok->width > ft_strlen(*toprint))
		pad_with_char(toprint, tok->width, ' ', !(tok->minus_flag));
}

void	add_base_prefix(char **toprint, t_token *tok, char *prefix)
{
	char	*res;

	if (!*toprint || (tok->spec != 'p' && !tok->prefix))
		return ;
	res = ft_strjoin(prefix, *toprint);
	free(*toprint);
	*toprint = res;
}
