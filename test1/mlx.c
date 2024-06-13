/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:22:02 by rkawahar          #+#    #+#             */
/*   Updated: 2024/06/13 11:12:01 by rkawahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img -> addr + (y * data->img->line_length + x * (data->img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_mlx(t_data vars)
{
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "fractol");
	vars.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
}
