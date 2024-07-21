/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.memtest.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <parden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:45:29 by parden            #+#    #+#             */
/*   Updated: 2024/06/04 18:22:39 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <stdio.h>
#include "libft.h"

Test(count_tok, mandatory)
{
	cr_expect_eq(count_tok("I live sheltered by luxurious ifelse tree forests"), 0);
	cr_expect_eq(count_tok("n = %d in block x = %x\nAt address %p"), 3);
	cr_expect_eq(count_tok("%c%s%p%d%i%u%x%X"), 8);
	cr_expect_eq(count_tok("Qui pour %s le %s pos %%pos%%\nMerde %%%%pos%%%%\nUwU %d,%d\n"), 10);
	cr_expect_eq(count_tok("%%%d%%%u%%cs%%p%x%X%%"), 9);
	cr_expect_eq(count_tok(""), 0);
}


Test(count_tok, with_flags)
{
	cr_expect_eq(count_tok("I l---ive 000sheltered by l4354uxuri000ous ifel###se tr#ee forests"), 0);
	cr_expect_eq(count_tok("n = % 05d in block x = %#-x\nAt address %-12p"), 3);
	cr_expect_eq(count_tok("%-7c%.3s%#0 -+12.7% %014p% 4d%++ +i%u%#x%--00-0--07X"), 9);
}

Test(tokenize, mandatory)
{
	char **token_strs = ft_calloc(1, sizeof(char *));
	tokenize(token_strs, "I live sheltered by luxurious ifelse tree forests");
	cr_expect_null(token_strs[0]);
	free_token_strs(token_strs);

	token_strs = ft_calloc(4, sizeof(char *));
	tokenize(token_strs,"n = %d in block x = %x\nAt address %p");
	cr_expect_str_eq(token_strs[0], "d");
	cr_expect_str_eq(token_strs[1], "x");
	cr_expect_str_eq(token_strs[2], "p");
	cr_expect_null(token_strs[3]);
	free_token_strs(token_strs);

	token_strs = ft_calloc(9, sizeof(char *));
	tokenize(token_strs,"%c%s%p%d%i%u%x%X");
	cr_expect_str_eq(token_strs[0], "c");
	cr_expect_str_eq(token_strs[1], "s");
	cr_expect_str_eq(token_strs[2], "p");
	cr_expect_str_eq(token_strs[3], "d");
	cr_expect_str_eq(token_strs[4], "i");
	cr_expect_str_eq(token_strs[5], "u");
	cr_expect_str_eq(token_strs[6], "x");
	cr_expect_str_eq(token_strs[7], "X");
	cr_expect_null(token_strs[8]);
	free_token_strs(token_strs);

	token_strs = ft_calloc(11, sizeof(char *));
	tokenize(token_strs,"Qui pour %s le %s pos %%pos%%\nMerde %%%%pos%%%%\nUwU %d,%d\n");
	cr_expect_str_eq(token_strs[0], "s");
	cr_expect_str_eq(token_strs[1], "s");
	cr_expect_str_eq(token_strs[2], "%");
	cr_expect_str_eq(token_strs[3], "%");
	cr_expect_str_eq(token_strs[4], "%");
	cr_expect_str_eq(token_strs[5], "%");
	cr_expect_str_eq(token_strs[6], "%");
	cr_expect_str_eq(token_strs[7], "%");
	cr_expect_str_eq(token_strs[8], "d");
	cr_expect_str_eq(token_strs[9], "d");
	cr_expect_null(token_strs[10]);
	free_token_strs(token_strs);

	token_strs = ft_calloc(10, sizeof(char *));
	tokenize(token_strs,"%%%d%%%u%%cs%%p%x%X%%");
	cr_expect_str_eq(token_strs[0], "%");
	cr_expect_str_eq(token_strs[1], "d");
	cr_expect_str_eq(token_strs[2], "%");
	cr_expect_str_eq(token_strs[3], "u");
	cr_expect_str_eq(token_strs[4], "%");
	cr_expect_str_eq(token_strs[5], "%");
	cr_expect_str_eq(token_strs[6], "x");
	cr_expect_str_eq(token_strs[7], "X");
	cr_expect_str_eq(token_strs[8], "%");
	cr_expect_null(token_strs[9]);
	free_token_strs(token_strs);

	token_strs = ft_calloc(1, sizeof(char *));
	tokenize(token_strs,"");
	cr_expect_null(token_strs[0]);
	free_token_strs(token_strs);
}

Test(tokenize, with_flags)
{
	char **token_strs = ft_calloc(1, sizeof(char *));
	tokenize(token_strs,"I l---ive 000sheltered by l4354uxuri000ous ifel###se tr#ee forests");
	cr_expect_null(token_strs[0]);
	free_token_strs(token_strs);

	token_strs = ft_calloc(4, sizeof(char *));
	tokenize(token_strs,"n = % 05d in block x = %#-x\nAt address %-12p");
	cr_expect_str_eq(token_strs[0], " 05d");
	cr_expect_str_eq(token_strs[1], "#-x");
	cr_expect_str_eq(token_strs[2], "-12p");
	cr_expect_null(token_strs[3]);
	free_token_strs(token_strs);

	token_strs = ft_calloc(10, sizeof(char *));
	tokenize(token_strs,"%-7c%.3s%#0 -+12.7% %014p% 4d%++ +i%u%#x%--00-0--07X");
	cr_expect_str_eq(token_strs[0], "-7c");
	cr_expect_str_eq(token_strs[1], ".3s");
	cr_expect_str_eq(token_strs[2], "#0 -+12.7%");
	cr_expect_str_eq(token_strs[3], "014p");
	cr_expect_str_eq(token_strs[4], " 4d");
	cr_expect_str_eq(token_strs[5], "++ +i");
	cr_expect_str_eq(token_strs[6], "u");
	cr_expect_str_eq(token_strs[7], "#x");
	cr_expect_str_eq(token_strs[8], "--00-0--07X");
	cr_expect_null(token_strs[9]);
	free_token_strs(token_strs);
}

Test(parse, mandatory)
{
	t_token **toks = parse("I live sheltered by luxurious ifelse tree forests");
	cr_expect_null(toks[0]);
	free_token_list(toks);

	toks = parse("n = %d in block x = %x\nAt address %p");
	cr_expect_eq(toks[0]->spec, 'd');
	cr_expect_eq(toks[1]->spec, 'x');
	cr_expect_eq(toks[2]->spec, 'p');
	cr_expect_null(toks[3]);
	free_token_list(toks);

	toks = parse("%c%s%p%d%i%u%x%X");
	cr_expect_eq(toks[0]->spec, 'c');
	cr_expect_eq(toks[1]->spec, 's');
	cr_expect_eq(toks[2]->spec, 'p');
	cr_expect_eq(toks[3]->spec, 'd');
	cr_expect_eq(toks[4]->spec, 'i');
	cr_expect_eq(toks[5]->spec, 'u');
	cr_expect_eq(toks[6]->spec, 'x');
	cr_expect_eq(toks[7]->spec, 'X');
	cr_expect_null(toks[8]);
	free_token_list(toks);

	toks = parse("Qui pour %s le %s pos %%pos%%\nMerde %%%%pos%%%%\nUwU %d,%d\n");
	cr_expect_eq(toks[0]->spec, 's');
	cr_expect_eq(toks[1]->spec, 's');
	cr_expect_eq(toks[2]->spec, '%');
	cr_expect_eq(toks[3]->spec, '%');
	cr_expect_eq(toks[4]->spec, '%');
	cr_expect_eq(toks[5]->spec, '%');
	cr_expect_eq(toks[6]->spec, '%');
	cr_expect_eq(toks[7]->spec, '%');
	cr_expect_eq(toks[8]->spec, 'd');
	cr_expect_eq(toks[9]->spec, 'd');
	cr_expect_null(toks[10]);
	free_token_list(toks);

	toks = parse("%%%d%%%u%%cs%%p%x%X%%");
	cr_expect_eq(toks[0]->spec, '%');
	cr_expect_eq(toks[1]->spec, 'd');
	cr_expect_eq(toks[2]->spec, '%');
	cr_expect_eq(toks[3]->spec, 'u');
	cr_expect_eq(toks[4]->spec, '%');
	cr_expect_eq(toks[5]->spec, '%');
	cr_expect_eq(toks[6]->spec, 'x');
	cr_expect_eq(toks[7]->spec, 'X');
	cr_expect_eq(toks[8]->spec, '%');
	cr_expect_null(toks[9]);
	free_token_list(toks);

	toks = parse("");
	cr_expect_null(toks[0]);
	free_token_list(toks);
}

Test(parse, with_flags)
{
	t_token **toks = parse("I l---ive 000sheltered by l4354uxuri000ous ifel###se tr#ee forests");
	cr_expect_null(toks[0]);
	free_token_list(toks);

	toks = parse("n = % 05d in block x = %#-x\nAt address %-12p");
	cr_expect_eq(toks[0]->spec, 'd');
	cr_expect(toks[0]->zero_flag);
	cr_expect_eq(toks[0]->sign,' ');
	cr_expect_eq(toks[0]->width, 5);

	cr_expect_eq(toks[1]->spec, 'x');
	cr_expect(toks[1]->prefix);
	cr_expect(toks[1]->minus_flag);

	cr_expect_eq(toks[2]->spec, 'p');
	cr_expect(toks[2]->minus_flag);
	cr_expect_eq(toks[2]->width, 12);

	cr_expect_null(toks[3]);
	free_token_list(toks);

	toks = parse("%-7c%.3s%#0 -+12.7% %014p% 4d%++ +i%u%#x%--00-0--07X");
	cr_expect_eq(toks[0]->spec, 'c');
	cr_expect(toks[0]->minus_flag);
	cr_expect_eq(toks[0]->width, 7);

	cr_expect_eq(toks[1]->spec, 's');
	cr_expect_eq(toks[1]->precision, 3);

	cr_expect_eq(toks[2]->spec, '%');

	cr_expect_eq(toks[3]->spec, 'p');
	cr_expect(toks[3]->zero_flag);
	cr_expect_eq(toks[3]->width, 14);

	cr_expect_eq(toks[4]->spec, 'd');
	cr_expect_eq(toks[4]->sign, ' ');
	cr_expect_eq(toks[4]->width, 4);

	cr_expect_eq(toks[5]->spec, 'i');
	cr_expect_eq(toks[5]->sign, '+');

	cr_expect_eq(toks[6]->spec, 'u');

	cr_expect_eq(toks[7]->spec, 'x');
	cr_expect(toks[7]->prefix);

	cr_expect_eq(toks[8]->spec, 'X');
	cr_expect(toks[8]->minus_flag);
	cr_expect_eq(toks[8]->width, 7);
	cr_expect_null(toks[9]);
	free_token_list(toks);
}

Test(parse, just_a_dot_sets_precision_to_zero)
{
	t_token **toks = parse("%.d");
	cr_expect_eq(toks[0]->spec, 'd');
	cr_expect_eq(toks[0]->precision, 0);
	cr_expect_null(toks[1]);
	free_token_list(toks);
}
