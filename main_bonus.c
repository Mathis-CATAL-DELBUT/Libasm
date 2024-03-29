#include "libasm_bonus.h"

int	is_ws(char c)
{
	return (c == 32 || ((c >= 9) && (c <= 13)));
}
int	baselen(char *base)
{
	int	base_len;

	base_len = 0;
	while (base[base_len])
		base_len++;
	return (base_len);
}
int	check_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
int	is_valid_param(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		if ((str[i] == '+') || str[i] == '-'
			|| (str[i] >= 9 && str[i] <= 13)
			|| str[i] == ' ')
			return (0);
		i++;
	}
	if (i < 2)
		return (0);
	return (1);
}
int	atoi_base(char *str, char *base)
{
	int	i;
	int	res;
	int	neg;

	i = 0;
	res = 0;
	neg = 1;
	if (is_valid_param(base))
	{
		while (is_ws(str[i]))
			i++;
		while ((str[i] == '+') || (str[i] == '-'))
		{
			if (str[i] == '-')
				neg *= -1;
			i++;
		}
		while (check_index(str[i], base) != -1)
		{
			res = res * baselen(base) + check_index(str[i], base);
			i++;
		}
		return (neg * res);
	}
	return (0);
}

static void	do_test(char *s, char *base)
{
	int	ori;
	int	ft;

	ft = ft_atoi_base(s, base);
	ori = atoi_base(s, base);
	if (ori != ft)
		printf("ft_atoi_base : %d || atoi_base : %d ❌\n", ft, ori);
	else
		printf("ft_atoi_base : %d || atoi_base : %d ✅\n", ft, ori);
}

void	ft_test_atoi_base(void)
{
	printf("\n\n###################   ft_atoi_base   ###################\n");
	do_test(" \t\v\r\n\f+-abc", "abcdefghij");
	do_test("34343434343434", "01234567");
	do_test("424242", "424242");
	do_test("424242", "42");
	do_test("NO BASE!!!", "");
	do_test("INCLUDE WHITESPACE!!!", " \t\v\r\n\f+-");
	do_test(" a", " a");
	do_test("1234", "");
	do_test("1234", "0");
	do_test("1234", "01");
}

int	main(void)
{
	ft_test_atoi_base();
	return (0);
}