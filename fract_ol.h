/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 13:08:19 by rkawahar          #+#    #+#             */
/*   Updated: 2024/06/13 09:46:55 by rkawahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>

typedef struct s_fractol {
	double	c_x;
	double	c_y;
	double	magni;
	double	center_x;
	double	center_y;
	int		color_factor;
}	t_fractol;

typedef struct s_data {
	void		*win;
	void		*mlx;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_fractol	frac;
}				t_data;

# define WIDTH 1920
# define HEIGHT 1080

int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_perror(void);
size_t	ft_strlen(const char *s);
void	ft_julia(void);
void	ft_mlx(t_data *vars);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		close_window(t_data *vars);
void	draw_mandelbrot(t_data *vars);
int		ft_zoom_mandel(int key, t_data *vars);
int		key_commands_mandel(int key, t_data *vars);
void	ft_mandelbrot(t_data *vars);

#endif