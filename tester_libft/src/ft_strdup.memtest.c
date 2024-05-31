/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.memtest.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <parden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:09:52 by parden            #+#    #+#             */
/*   Updated: 2024/05/17 17:34:01 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stddef.h>
#include <signal.h>
#include <sanitizer/lsan_interface.h>
#include <criterion/criterion.h>
#include "libft.h"

Test(strdup, basic)
{
	char *s = ft_strdup("Y'as que m0i /n\n qui va lèr\" ça...");
	cr_expect_str_eq("Y'as que m0i /n\n qui va lèr\" ça...", s);
	free(s);
}

Test(strdup, empty)
{
	char *s1 = ft_strdup("");
	cr_expect_str_eq("", s1);
	free(s1);
}

Test(strdup, big_ass_string)
{
	char s[100000];

	for (int i = 0; i < 99999; i++)
	{
		s[i] = 'X';
	}
	s[99999] = 0;
	char *s1 = ft_strdup(s);
	cr_expect_str_eq(s, s1);
	free(s1);
}

Test(strdup, exact_alloc, .signal = SIGABRT)
{
	char *s = ft_strdup("q");
	int i = s[2];
	free(s);
	i++;
}

//doesnt work with clang, dont know why
Test(strdup, leaky, .signal = SIGABRT)
{
	ft_strdup("leak")[2]=4;
	cr_expect(__lsan_do_recoverable_leak_check());
	__lsan_do_leak_check();
}

