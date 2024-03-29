/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:46:08 by ymehlil           #+#    #+#             */
/*   Updated: 2024/03/28 09:23:31 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			if ((str[i] == str[j]))
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

int	ft_atoi_base(char *str, char *base)
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
