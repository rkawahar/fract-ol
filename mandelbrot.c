/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:50:13 by rkawahar          #+#    #+#             */
/*   Updated: 2024/06/14 21:04:49 by rkawahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	div_julia(int x, int y, t_data *vars)
{
	int		i;
	double	xx;
	double	yy;
	double	tmp;

	i = 0;
	xx = (double)(x - WIDTH / 2) / (WIDTH * vars->frac.magni) * 4
		+ vars->frac.center_x;
	yy = (double)(y - HEIGHT / 2) / (HEIGHT * vars->frac.magni) * 4
		+ vars->frac.center_y;
	while (++i <= 100)
	{
		if (xx * xx + yy * yy > 4)
			return (i);
		tmp = xx;
		xx = xx * xx - yy * yy + vars->frac.c_x;
		yy = 2 * tmp * yy + vars->frac.c_y;
	}
	return (0);
}

void	draw_julia(t_data *vars)
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
			color = div_julia(x, y, vars);
			color *= vars->frac.color_factor;
			prot_pixel(x, y, color, vars);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}

void	ft_julia(t_data vars)
{
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "Julia");
	vars.img.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	mlx_hook(vars.win, 17, 0, close_window, &vars);
	mlx_mouse_hook(vars.win, zoom_julia, &vars);
	mlx_key_hook(vars.win, key_commands_julia, &vars);
	draw_julia(&vars);
	mlx_loop(vars.mlx);
}
