/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoll.memtest.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <parden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:09:52 by parden            #+#    #+#             */
/*   Updated: 2024/09/24 20:11:33 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <signal.h>
#include <criterion/criterion.h>
#include "libft.h"

Test(strtol, atoi_like)
{
	cr_expect_eq(atoi("0"), ft_strtoll("0",NULL,NULL));
	cr_expect_eq(atoi("1"), ft_strtoll("1",NULL,NULL));
	cr_expect_eq(atoi("-1"), ft_strtoll("-1",NULL,NULL));
	cr_expect_eq(atoi("2147483647"), ft_strtoll("2147483647",NULL,NULL));
	cr_expect_eq(atoi("-2147483648"), ft_strtoll("-2147483648",NULL,NULL));
	cr_expect_eq(atoi("     /t /f/f/n   /n +158385aa57"), ft_strtoll("     /t /f/f/n   /n +158385aa56aa57",NULL,NULL));
	cr_expect_eq(atoi("--1"), ft_strtoll("--1",NULL,NULL));
	cr_expect_eq(atoi(""), ft_strtoll("",NULL,NULL));
	cr_expect_eq(atoi("12 34"), ft_strtoll("12 34",NULL,NULL));
	cr_expect_eq(atoi("-000154"), ft_strtoll("-000154",NULL,NULL));
	cr_expect_eq(atoi(" "), ft_strtoll(" ",NULL,NULL));
	cr_expect_eq(atoi(" - "), ft_strtoll(" - ",NULL,NULL));
	cr_expect_eq(atoi(" +"), ft_strtoll(" +",NULL,NULL));
	cr_expect_eq(atoi(" + 1"), ft_strtoll(" + 1",NULL,NULL));
	cr_expect_eq(atoi("0000000000000000000000000"), ft_strtoll("0000000000000000000000000",NULL,NULL));
}

Test(strtol, overflow)
{
	bool overflow;

	cr_expect_eq(LLONG_MAX, ft_strtoll("9223372036854775807",NULL,&overflow));
	cr_expect_eq(overflow, false);

	cr_expect_eq(LLONG_MIN, ft_strtoll("-9223372036854775808",NULL,&overflow));
	cr_expect_eq(overflow, false);

	cr_expect_eq(LLONG_MAX, ft_strtoll("9223372036854775808",NULL,&overflow));
	cr_expect_eq(overflow, true);

	cr_expect_eq(LLONG_MIN, ft_strtoll("-9223372036854775809",NULL,&overflow));
	cr_expect_eq(overflow, true);

	cr_expect_eq(LLONG_MAX-1, ft_strtoll("9223372036854775806",NULL,&overflow));
	cr_expect_eq(overflow, false);

	cr_expect_eq(LLONG_MIN + 1, ft_strtoll("-9223372036854775807",NULL,&overflow));
	cr_expect_eq(overflow, false);

	//printf ("%lld, %lld\n", LLONG_MIN, ft_strtoll("-9223372036854775809",NULL,NULL));
}

Test(strtoll, fdf)
{
	char *endptr;
	char *str = "53456,0XDEADBEEF";

	ft_strtoll(str, &endptr, NULL);
	cr_expect_eq(str + 5, endptr);
	cr_expect_eq(3735928559, ft_strtoll(str + 6, NULL, NULL));
}
