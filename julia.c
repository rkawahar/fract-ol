/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:26:27 by rkawahar          #+#    #+#             */
/*   Updated: 2024/06/07 20:31:34 by rkawahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	ft_julia(void)
{
	void	*mlx;
	void	*win;
	void	*img;

	mlx = mlx_init();
	if (mlx == NULL)
		ft_perror();
	win = mlx_new_window(mlx, WIDTH, HEIGHT, "fract_ol");
	if (win == NULL)
		ft_perror();
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (img == NULL)
		ft_perror();
	
}
