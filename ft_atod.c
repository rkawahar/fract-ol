/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:56:46 by rkawahar          #+#    #+#             */
/*   Updated: 2024/06/13 20:53:24 by rkawahar         ###   ########.fr       */
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

double	ft_atod(char *num)
{
	double	ans;
	int		before;
	int		after;
	int		i;

	
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
	vars -> frac.c_x = ft_atod(str2);
	(void)vars;
	free(str1);
	free(str2);
}
