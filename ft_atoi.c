/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:59:52 by rkawahar          #+#    #+#             */
/*   Updated: 2024/06/14 17:35:09 by rkawahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static int	checker(char c, long num, int flg)
{
	if (num == 0)
		return (0);
	if (flg == -1)
	{
		num *= -1;
		if ((LONG_MIN + (c - '0')) / 10 > num)
			return (1);
	}
	else
	{
		if ((LONG_MAX - (c - '0')) / 10 < num)
			return (1);
	}
	return (0);
}

int	checker2(int flg)
{
	if (flg == 1)
		return ((int)LONG_MAX);
	else
		return ((int)LONG_MIN);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	long	num;
	int		neg_flg;

	num = 0;
	i = 0;
	neg_flg = 1;
	while (str[i] == 32 || (9 <= str[i] && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		neg_flg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while ('0' <= str[i] && str[i] <= '9')
	{
		if (checker(str[i], num, neg_flg))
			return (checker2(neg_flg));
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	num *= neg_flg;
	return (num);
}
