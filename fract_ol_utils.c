/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:11:12 by rkawahar          #+#    #+#             */
/*   Updated: 2024/06/07 20:26:50 by rkawahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	ft_perror(void)
{
	perror(NULL);
	exit(1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && s1[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

size_t	ft_strlen(const char *s)
{
	int	ans;

	ans = 0;
	while (*s)
	{
		ans++;
		s++;
	}
	return (ans);
}

// void	draw_pixel(void *vars, int x, int y, unsigned int color)
// {
// 	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
// 		return ;
// 	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel,
// 			&vars->img.line_length, &vars->img.endian);
// 	my_mlx_pixel_put(&vars->img, x, y, color);
// 	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
// }