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

void	ft_test_atoi_base(void)
{
	printf("\n\n###################   ft_atoi_base   ###################\n");
	int	ori;
	int	ft;

	ft = ft_atoi_base(" \t\v\r\n\f+-abc", "abcdefghij");
	ori = atoi_base(" \t\v\r\n\f+-abc", "abcdefghij");
	if (ori != ft)
		printf("ft_atoi_base : %d || atoi_base : %d ❌\n", ft, ori);
	else
		printf("ft_atoi_base : %d || atoi_base : %d ✅\n", ft, ori);

	ft = ft_atoi_base("34343434343434", "01234567");
	ori = atoi_base("34343434343434", "01234567");
	if (ori != ft)
		printf("ft_atoi_base : %d || atoi_base : %d ❌\n", ft, ori);
	else
		printf("ft_atoi_base : %d || atoi_base : %d ✅\n", ft, ori);
	
	ft = ft_atoi_base("424242", "424242");
	ori = atoi_base("424242", "424242");
	if (ori != ft)
		printf("ft_atoi_base : %d || atoi_base : %d ❌\n", ft, ori);
	else
		printf("ft_atoi_base : %d || atoi_base : %d ✅\n", ft, ori);

	ft = ft_atoi_base("424242", "42");
	ori = atoi_base("424242", "42");
	if (ori != ft)
		printf("ft_atoi_base : %d || atoi_base : %d ❌\n", ft, ori);
	else
		printf("ft_atoi_base : %d || atoi_base : %d ✅\n", ft, ori);

	ft = ft_atoi_base("NO BASE!!!", "");
	ori = atoi_base("NO BASE!!!", "");
	if (ori != ft)
		printf("ft_atoi_base : %d || atoi_base : %d ❌\n", ft, ori);
	else
		printf("ft_atoi_base : %d || atoi_base : %d ✅\n", ft, ori);

	ft = ft_atoi_base("INCLUDE WHITESPACE!!!", " \t\v\r\n\f+-");
	ori = atoi_base("INCLUDE WHITESPACE!!!", " \t\v\r\n\f+-");
	if (ori != ft)
		printf("ft_atoi_base : %d || atoi_base : %d ❌\n", ft, ori);
	else
		printf("ft_atoi_base : %d || atoi_base : %d ✅\n", ft, ori);

	ft = ft_atoi_base(" a", " a");
	ori = atoi_base(" a", " a");
	if (ori != ft)
		printf("ft_atoi_base : %d || atoi_base : %d ❌\n", ft, ori);
	else
		printf("ft_atoi_base : %d || atoi_base : %d ✅\n", ft, ori);

	ft = ft_atoi_base("1234", "");
	ori = atoi_base("1234", "");
	if (ori != ft)
		printf("ft_atoi_base : %d || atoi_base : %d ❌\n", ft, ori);
	else
		printf("ft_atoi_base : %d || atoi_base : %d ✅\n", ft, ori);

	ft = ft_atoi_base("1234", "0");
	ori = atoi_base("1234", "0");
	if (ori != ft)
		printf("ft_atoi_base : %d || atoi_base : %d ❌\n", ft, ori);
	else
		printf("ft_atoi_base : %d || atoi_base : %d ✅\n", ft, ori);

	ft = ft_atoi_base("1234", "01");
	ori = atoi_base("1234", "01");
	if (ori != ft)
		printf("ft_atoi_base : %d || atoi_base : %d ❌\n", ft, ori);
	else
		printf("ft_atoi_base : %d || atoi_base : %d ✅\n", ft, ori);
}

void	ft_clear_lst(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}


void	ft_test_list_push_front(void)
{
	printf("\n\n###################   ft_list_push_front   ###################\n");
	const char	*data = "data";
	t_list		*list;
	t_list		*list_old;

	list = malloc(sizeof(t_list));
	if (list == NULL)
		return;
	list_old = list;
	list->next = 0;
	ft_list_push_front(&list, (void *)data);
	if (list == list_old || list->data != data || list->next != list_old)
		printf("ft_list_push_front : ❌\n");
	else
		printf("ft_list_push_front : ✅\n");
	ft_clear_lst(list);
}

void	ft_test_list_size(void)
{
	printf("\n\n###################   ft_list_size   ###################\n");
	t_list	*list;
	int		size;

	list = malloc(sizeof(t_list));
	if (list == NULL)
		return;
	list->data = (void *)"data";
	list->next = 0;
	size = ft_list_size(list);
	if (size != 1)
		printf("ft_list_size : %d || list size : %d ❌\n", size, 1);
	else
		printf("ft_list_size : %d || list size : %d ✅\n", size, 1);

	ft_list_push_front(&list, (void *)"data");
	size = ft_list_size(list);
	if (size != 2)
		printf("ft_list_size : %d || list size : %d ❌\n", size, 2);
	else
		printf("ft_list_size : %d || list size : %d ✅\n", size, 2);

	ft_list_push_front(&list, (void *)"data");
	size = ft_list_size(list);
	if (size != 3)
		printf("ft_list_size : %d || list size : %d ❌\n", size, 3);
	else
		printf("ft_list_size : %d || list size : %d ✅\n", size, 3);

	ft_list_push_front(&list, (void *)"data");
	size = ft_list_size(list);
	if (size != 4)
		printf("ft_list_size : %d || list size : %d ❌\n", size, 4);
	else
		printf("ft_list_size : %d || list size : %d ✅\n", size, 4);

	ft_list_push_front(&list, (void *)"data");
	size = ft_list_size(list);
	if (size != 5)
		printf("ft_list_size : %d || list size : %d ❌\n", size, 5);
	else
		printf("ft_list_size : %d || list size : %d ✅\n", size, 5);
	ft_clear_lst(list);
}

int	main(void)
{
	ft_test_atoi_base();
	ft_test_list_push_front();
	ft_test_list_size();
	return (0);
}