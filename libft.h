/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <parden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:42:49 by parden            #+#    #+#             */
/*   Updated: 2024/05/31 13:40:52 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <limits.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>


# define SPECIFIERS "cspdiuxX%"
# define FLAGS "0-+ #"

# define BASE10 "0123456789"
# define UPBASE16 "0123456789ABCDEF"
# define LOBASE16 "0123456789abcdef"

# ifndef FD_MAX
#  define FD_MAX 16
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

//			CTYPE
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);

//			STRING
void	ft_bzero(void *s, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

//			STDLIB
int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);
void	*ft_calloc(size_t nelem, size_t elsize);

//			STDIO
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*get_next_line(int fd);

//			PRINTF
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

//			LST
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
#endif
