#include "libft.h"
#include <criterion/criterion.h>
#include <signal.h>
#include <stdio.h>

void free2d(char **split)
{
	size_t i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

Test(split, basics)
{
	char *s = ",153,5,,,453,4,321,5,-15,,,";
	char **test = ft_split(s, ',');
	cr_assert_str_eq(test[0],"153");
	cr_assert_str_eq(test[1],"5");
	cr_assert_str_eq(test[2],"453");
	cr_assert_str_eq(test[3],"4");
	cr_assert_str_eq(test[4],"321");
	cr_assert_str_eq(test[5],"5");
	cr_assert_str_eq(test[6],"-15");
	cr_assert_null(test[7]);
	free2d(test);

	test = ft_split(s, 'w');
	cr_assert_str_eq(test[0],s);
	cr_assert_null(test[1]);
	free2d(test);

	s = ",,,,,,,,,,,,";
	test = ft_split(s, ',');
	cr_assert_null(test[0]);
	free2d(test);

	s = "";
	test = ft_split(s, ',');
	cr_assert_null(test[0]);
	free2d(test);
}

Test(split, Schrodingers_bug)
{
	char *s = "Tripouille";
	char **test = ft_split(s, '~');
	cr_assert_str_eq(test[0],"Tripouille");
	cr_assert_null(test[1]);
	free2d(test);

	test = ft_split(s, '0');
	cr_assert_str_eq(test[0],"Tripouille");
	cr_assert_null(test[1]);
	free2d(test);

	test = ft_split(s, 'W');
	cr_assert_str_eq(test[0],"Tripouille");
	cr_assert_null(test[1]);
	free2d(test);

	test = ft_split(s, '\v');
	cr_assert_str_eq(test[0],"Tripouille");
	cr_assert_null(test[1]);
	free2d(test);

}
