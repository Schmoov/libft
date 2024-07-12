/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:30:15 by parden            #+#    #+#             */
/*   Updated: 2024/06/04 18:21:55 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define SPECIFIERS "cspdiuxX%"
# define FLAGS "0-+ #"

# define BASE10 "0123456789"
# define UPBASE16 "0123456789ABCDEF"
# define LOBASE16 "0123456789abcdef"

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "include/libft.h"

//pad can be \0 (right-justify), '-' (left-justify), or '0' (pad with zero)
//->0>/0
//sign can be \0 (no plus sign) ' ' (blank as plus sign) or '+' (yes plus sign)
//+>' '>\0
//prefix can be \0 (no prefix) or '#' (yes prefix)
//default width is 0
typedef struct s_token
{
	char		spec;
	bool		minus_flag;
	bool		zero_flag;
	char		sign;
	bool		prefix;
	int			width;
	bool		has_prec;
	int			precision;
}				t_token;
size_t	free_token_strs(char **token_strs);
size_t	count_tok(const char *s);
int		tokenize(char **token_strs, const char *s);
void	*free_token_list(t_token **token_list);
t_token	*parse_one(const char *token_str);
t_token	**parse(const char *s);
char	*itoa_base(int n, char *base, bool is_signed);
char	*ptrtoa_base(void *p, char *base);
void	skip_past_token(char **s);
int		print_until_percent(char **s);
int		percent_printer(void);
char	*str_filled_with_char(int len, char c);
void	pad_with_char(char **toprint, int output_len, char c, bool leftpad);
void	add_precision_zeroes(char **toprint, t_token *tok);
void	add_width_zeroes(char **toprint, t_token *tok, int prefix_width);
void	add_width_blanks(char **toprint, t_token *tok);
void	add_sign(char **toprint, t_token *tok);
void	add_base_prefix(char **toprint, t_token *tok, char *prefix);
int		percent_printer(void);
int		c_printer(t_token *tok, int n);
int		d_printer(t_token *tok, int n);
int		u_printer(t_token *tok, int n);
int		xlo_printer(t_token *tok, int n);
int		xup_printer(t_token *tok, int n);
int		s_printer(t_token *tok, void *p);
int		p_printer(t_token *tok, void *p);
int		ft_printf(const char *format, ...);
#endif
