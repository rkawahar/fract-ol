/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:18:44 by rkawahar          #+#    #+#             */
/*   Updated: 2024/06/14 18:59:33 by rkawahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	zoom_mandel(int key, int x, int y, t_data *vars)
{
	(void)x;
	(void)y;
	if (key == 5)
		vars -> frac.magni *= 1.25;
	else if (key == 4)
		vars -> frac.magni *= 0.8;
	draw_mandelbrot(vars);
	return (0);
}

int	key_commands(int key, t_data *vars)
{
	if (key == 123)
		vars -> frac.center_x -= 0.5 / vars -> frac.magni;
	else if (key == 124)
		vars -> frac.center_x += 0.5 / vars -> frac.magni;
	else if (key == 126)
		vars -> frac.center_y -= 0.5 / vars -> frac.magni;
	else if (key == 125)
		vars -> frac.center_y += 0.5 / vars -> frac.magni;
	else if (key == 53 || key == 51)
		close_window(vars);
	else if (key == 49)
		vars -> frac.color_factor += 1;
	draw_mandelbrot(vars);
	return (0);
}

void	my_mlx_pixel_put(t_img *data, int x, int y, unsigned int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	zoom_julia(int key, int x, int y, t_data *vars)
{
	(void)x;
	(void)y;
	if (key == 5)
		vars -> frac.magni *= 1.25;
	else if (key == 4)
		vars -> frac.magni *= 0.8;
	draw_julia(vars);
	return (0);
}

int	key_commands_julia(int key, t_data *vars)
{
	if (key == 123)
		vars -> frac.center_x -= 0.5 / vars -> frac.magni;
	else if (key == 124)
		vars -> frac.center_x += 0.5 / vars -> frac.magni;
	else if (key == 126)
		vars -> frac.center_y -= 0.5 / vars -> frac.magni;
	else if (key == 125)
		vars -> frac.center_y += 0.5 / vars -> frac.magni;
	else if (key == 53 || key == 51)
		close_window(vars);
	else if (key == 49)
		vars -> frac.color_factor += 1;
	draw_julia(vars);
	return (0);
}
