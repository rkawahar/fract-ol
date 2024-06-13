/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:27:38 by rkawahar          #+#    #+#             */
/*   Updated: 2024/06/13 10:22:55 by rkawahar         ###   ########.fr       */
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
	vars -> frac.c_x = (double)(x - 960) / (WIDTH * vars -> frac.magni) \
												+ vars -> frac.center_x;
	vars -> frac.c_y = (double)(y - 540) / (HEIGHT * vars -> frac.magni) \
												+ vars -> frac.center_y;
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

void	prot_pixel(int x, int y, int color, t_data *vars)
{
	if (y < 0 || HEIGHT <= y)
		return ;
	if (x < 0 || WIDTH <= x)
		return ;
	vars -> img -> addr = mlx_get_data_addr(vars -> img, &vars -> img -> bits_per_pixel, &vars -> img -> line_length, &vars -> img -> endian);
	my_mlx_pixel_put(vars -> img -> img, x, y, color * 1000);
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
			color *= vars -> frac.color_factor;
			prot_pixel(x, y, color, vars);
		}
		y++;
	}
	mlx_put_image_to_window(vars -> mlx, vars -> win, vars -> img -> img, 0, 0);
}

void	ft_mandelbrot(t_data *vars)
{
	ft_mlx(*vars);
	mlx_hook(vars -> win, 17, 0, close_window, vars);
	mlx_mouse_hook(vars -> win, ft_zoom_mandel, vars);
	mlx_key_hook(vars -> win, key_commands_mandel, vars);
	draw_mandelbrot(vars);
	mlx_loop(vars -> mlx);
}
