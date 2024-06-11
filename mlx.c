/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:22:02 by rkawahar          #+#    #+#             */
/*   Updated: 2024/06/11 14:27:12 by rkawahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_mlx(t_data *vars)
{
	vars -> mlx = mlx_init();
	vars -> win = mlx_new_window(vars -> mlx, WIDTH, HEIGHT, "fractol");
	vars -> img = mlx_new_image(vars -> mlx, WIDTH, HEIGHT);
	vars -> addr = mlx_get_data_addr(vars -> img, vars -> bits_per_pixel, \
		vars -> line_length, vars -> endian);
}
