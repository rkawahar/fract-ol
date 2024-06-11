/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:27:38 by rkawahar          #+#    #+#             */
/*   Updated: 2024/06/11 17:53:15 by rkawahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	div_mandel(int x, int y, t_data *vars)
{
	int		i;
	double	xx;
	double	yy;
	double	tmp;

	i = 0;
	xx = 0;
	yy = 0;
	vars -> frac.c_x = (double)(x - 960) + 960;
	vars -> frac.c_y = (double)(y - 540) + 540;
	while (i < 100)
	{
		if (xx * xx + yy * yy > 4)
			return (i);
		tmp = xx;
		xx = xx * xx - yy * yy + vars -> frac.c_x;
		yy = 2 * tmp * yy + vars -> frac.c_y;
	}
	return (0);
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
			color *= 
		}
		y++;
	}
}

void	ft_maldelbrot(t_data *vars)
{
	mlx_hook(vars -> win, 17, 0, close_window, vars);
	mlx_mouse_hook(vars -> win, ft_zoom_mandel, vars);
	mlx_key_hook(vars -> win, key_commands_mandel, vars);
	draw_mandelbrot(vars);
	mlx_loop(vars -> mlx);
}
