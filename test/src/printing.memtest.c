#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include "libft.h"

Test(metatest, a)
{
	cr_redirect_stdout();
	printf("la string en question\n");
	fflush(stdout);
	cr_assert_stdout_eq_str("la string en question\n","");
}

Test(metatest, b)
{
	cr_redirect_stdout();
	printf("la string 2\n");
	fflush(stdout);
	cr_assert_stdout_eq_str("la string 2\n","");
}


Test(printing, no_specs)
{
	int res = -69;
	char *str = "I live sheltered by luxurious ifelse tree forests";

	cr_redirect_stdout();
	res = ft_printf(str);
	fflush(stdout);
	cr_expect_stdout_eq_str(str);
	cr_expect_eq(res, (int)strlen(str));
}

Test(printing, some_specs)
{
	int res = -69;
	int exp_res;
	char *str = "n = %d in block x = %x\nAt address %p";
	char buffer[1000];

	cr_redirect_stdout();
	res = ft_printf(str, 14, 42, (void *)0);
	fflush(stdout);
	exp_res = sprintf(buffer, str, 14, 42, (void *)0);
	cr_expect_stdout_eq_str(buffer);
	cr_expect_eq(res, exp_res);
}

Test(printing, all_specs)
{
	int res = -69;
	int exp_res;
	char *str = "%c%s%p%d%i%u%x%X";
	char buffer[1000];

	cr_redirect_stdout();
	res = ft_printf(str,'x',"Billie Eilish",&res,INT_MAX,INT_MIN,UINT_MAX,0,45689);
	fflush(stdout);
	exp_res = sprintf(buffer,str,'x',"Billie Eilish",&res,INT_MAX,INT_MIN,UINT_MAX,0,45689);
	cr_expect_stdout_eq_str(buffer);
	cr_expect_eq(res, exp_res);
}

Test(printing, specs_and_percents)
{
	int res = -69;
	int exp_res;
	char *str = "Qui pour %s le %s pos %%pos%%\nMerde %%%%pos%%%%\nUwU %d,%d\n";
	char buffer[1000];

	cr_redirect_stdout();
	res = ft_printf(str,"Xaxani","Proproxo",-36,47);
	fflush(stdout);
	exp_res = sprintf(buffer,str,"Xaxani","Proproxo",-36,47);
	cr_expect_stdout_eq_str(buffer);
	cr_expect_eq(res, exp_res);
}

Test(printing, trickier_specs_and_percents)
{
	int res = -69;
	int exp_res;
	char *str = "%%%d%%%u%%cs%%p%x%X%%";
	char buffer[1000];

	cr_redirect_stdout();
	res = ft_printf(str,INT_MIN,0,UINT_MAX,0);
	fflush(stdout);
	exp_res = sprintf(buffer,str,INT_MIN,0,UINT_MAX,0);
	cr_expect_stdout_eq_str(buffer);
	cr_expect_eq(res, exp_res);
}

Test(printing, no_flags_but_looks_like_it)
{
	int res = -69;
	int exp_res;
	char *str = "I l---ive 000sheltered by l4354uxuri000ous ifel###se tr#ee forests";
	char buffer[1000];

	cr_redirect_stdout();
	res = ft_printf(str);
	fflush(stdout);
	exp_res = sprintf(buffer,"%s",str);
	cr_expect_stdout_eq_str(buffer);
	cr_expect_eq(res, exp_res);
}

Test(printing, some_flags)
{
	int res = -69;
	int exp_res;
	char *str = "n = % 05d in block x = %#-x\nAt address %-20p";
	char buffer[1000];

	cr_redirect_stdout();
	res = ft_printf(str,23456,4354976,&res);
	fflush(stdout);
	exp_res = sprintf(buffer,str,23456,4354976,&res);
	cr_expect_stdout_eq_str(buffer);
	cr_expect_eq(res, exp_res);
}

Test(printing, a_bunch_of_flags)
{
	int res = -69;
	int exp_res;
	char *str = "%-7c%.3s%#0 -+12.7% %17p% 4d%++ +i%u%#x%--00-0--07X";
	char buffer[1000];

	cr_redirect_stdout();
	res = ft_printf(str,'q',"WANNACRY",&res,INT_MAX,3958496,0,0,4969964);
	fflush(stdout);
	exp_res = sprintf(buffer,str,'q',"WANNACRY",&res,INT_MAX,3958496,0,0,4969964);
	cr_expect_stdout_eq_str(buffer);
	cr_expect_eq(res, exp_res);
}

Test(printing, all_dspec_flag_edge_cases)
{
	int res = -69;
	int exp_res;
	char *str = "zeroes|%.d|%.0d|%.1d|"
		"sign position for negative|%7.3d|%7d|%.7d|%07d|%07.3d|"
		"positives|%+7.3d|%+7d|%+.7d|%+07d|%+07.3d|"
		"left-justif|%-7.3d|%-7d|%-.7d|%-07d|%-07.3d|%-+7.3d|%-+7d|%-+.7d|%-+07d|%-+07.3d|";
	char buffer[5000];

	cr_redirect_stdout();
	res = ft_printf(str,0,0,0,-1,-1,-1,-1,-1,1,1,1,1,1,-1,-1,-1,-1,-1,1,1,1,1,1);
	fflush(stdout);
	exp_res = sprintf(buffer,str,0,0,0,-1,-1,-1,-1,-1,1,1,1,1,1,-1,-1,-1,-1,-1,1,1,1,1,1);
	cr_expect_stdout_eq_str(buffer);
	cr_expect_eq(res, exp_res);
}

Test(printing, francinette_print_NUL_char)
{
	int res = -69;
	char *str = "| %c %c %c | %c %c %c | %c %c %c |";

	cr_redirect_stdout();
	res = ft_printf(str,'0',0,'1','2','1',0,0,'1','2');
	fflush(stdout);
	FILE *expected_output = fopen("test/txt/francinette_cspec.txt", "r");
	cr_expect_stdout_eq(expected_output);
	fclose(expected_output);
	cr_expect_eq(res, 25);
}

Test(printing, francinette_str_NULL)
{
	int res = -69;
	int exp_res;
	char *str = "Cest 100%% UB mais bon :%s";
	char buffer[100];

	cr_redirect_stdout();
	res = ft_printf(str, (char *)0);
	fflush(stdout);
	exp_res = sprintf(buffer,str, (char *)0);
	cr_expect_stdout_eq_str(buffer);
	cr_expect_eq(res, exp_res);
}

Test(printing, 3edgy5me)
{
	int res = -69;
	int exp_res;
	char *str = "This fucker -> %#04x|%04X|%04p";
	char buffer[100];

	cr_redirect_stdout();
	res = ft_printf(str, 0, 0, (void *)0);
	fflush(stdout);
	exp_res = sprintf(buffer,str, 0, 0, (void *)0);
	cr_expect_stdout_eq_str(buffer);
	cr_expect_eq(res, exp_res);
}

