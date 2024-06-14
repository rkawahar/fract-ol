/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:56:46 by rkawahar          #+#    #+#             */
/*   Updated: 2024/06/14 20:29:34 by rkawahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	check_num(char *num)
{
	int	i;
	int	flg;

	i = 0;
	flg = 0;
	if (num[i] == '-')
		i++;
	while (num[i] != '\n')
	{
		if (num[i] < '0' || '9' < num[i])
		{
			if (num[i] == '.' && flg == 0)
				flg = 1;
			else
				return (0);
		}
		i++;
	}
	num[i] = '\0';
	return (i);
}

int	ft_without_dot(char *int_str, char *num)
{
	int	i;
	int	after;

	i = 0;
	while (num[i] != '.' && num[i])
	{
		int_str[i] = num[i];
		i++;
	}
	if (num[i] == '.')
		i++;
	after = -1;
	while (num[i + (++after)])
		int_str[i + after - 1] = num[i + after];
	int_str[i + after - 1] = '\0';
	return (after);
}

int	check_dot(char *num)
{
	int	i;

	i = 0;
	while (num[i] != '\0')
	{
		if (num[i] == '.')
			return (0);
		i++;
	}
	return (1);
}

double	ft_atod(char *num)
{
	double	ans;
	int		int_num;
	int		after;
	char	*int_str;
	int		flg;

	flg = check_dot(num);
	int_str = (char *)malloc(ft_strlen(num) + flg);
	if (int_str == NULL)
		exit(1);
	after = ft_without_dot(int_str, num);
	int_num = ft_atoi(int_str);
	ans = (double)int_num * pow(0.1, (double)after);
	free(int_str);
	return (ans);
}

void	ft_select_num(t_data *vars)
{
	char	*str1;
	char	*str2;

	write(1, "write number\n> ", 15);
	str1 = ft_gnl();
	if (check_num(str1) == 0)
	{
		write(1, "it is not a number\n", 19);
		exit(1);
	}
	write(1, "write number\n> ", 15);
	str2 = ft_gnl();
	if (check_num(str2) == 0)
	{
		write(1, "it is not a number\n", 19);
		exit(1);
	}
	vars -> frac.c_x = ft_atod(str1);
	vars -> frac.c_y = ft_atod(str2);
	free(str1);
	free(str2);
	ft_julia(*vars);
}
