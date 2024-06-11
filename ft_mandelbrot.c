/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:27:38 by rkawahar          #+#    #+#             */
/*   Updated: 2024/06/11 14:40:09 by rkawahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	div_mandel(int x, int y, t_data *vars)
{
	int		i;
	double	div_x;
	double	div_y;

	i = 0;
	div_x = 0;
	div_y = 0;
	vars
}

void	draw_mandelbrot(t_data *vars)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			color = div_mandel(x, y, vars);
		}
		y++;
	}
}

void	ft_maldelbrot(t_data *vars)
{
	draw_mandelbrot(vars);
	mlx_loop(vars -> mlx);
}