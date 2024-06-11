/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:45:49 by rkawahar          #+#    #+#             */
/*   Updated: 2024/06/11 18:10:18 by rkawahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	ft_zoom_mandel(int key, t_data *vars)
{
	if (key == 5)
		vars -> frac.magni *= 1.25;
	else if (key == 4)
		vars -> frac.magni *= 0.8;
	draw_mandelbrot(vars);
}

void	key_commands_mandel(int key, t_data *vars)
{
	if (key == 123)
		vars -> frac.center_x -= 0.5 / vars -> frac.magni;
	else if (key == 124)
		vars -> frac.center_y += 0.5 / vars -> frac.magni;
	else if (key == 125)
		vars -> frac.center_y -= 0.5 / vars -> frac.magni;
	else if (key == 126)
		vars -> frac.center_y += 0.5 / vars -> frac.magni;
	else if (key == 53 || key == 51)
		close_window(vars);
	else if (key == 49)
		vars -> frac.color_factor += 1;
	draw_mandelbrot(vars);
}
