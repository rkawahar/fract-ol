/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:56:24 by rkawahar          #+#    #+#             */
/*   Updated: 2024/06/14 19:11:58 by rkawahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <limits.h>
# include <math.h>

typedef struct s_fractol {
	double	c_x;
	double	c_y;
	double	magni;
	double	center_x;
	double	center_y;
	int		color_factor;
}	t_fractol;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_data {
	void		*win;
	void		*mlx;
	t_img		img;
	t_fractol	frac;
}				t_data;

# define WIDTH 1080
# define HEIGHT 1080

void	ft_perror(void);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
int		close_window(t_data *vars);
t_data	*ft_create_vars(void);
void	ft_mandelbrot(t_data vars);
int		zoom_mandel(int key, int x, int y, t_data *vars);
int		key_commands(int key, t_data *vars);
void	my_mlx_pixel_put(t_img *data, int x, int y, unsigned int color);
void	ft_select_num(t_data *vars);
void	draw_mandelbrot(t_data *vars);
char	*re_create(char *str, char tmp);
char	*ft_gnl(void);
int		ft_atoi(const char *str);
int		zoom_julia(int key, int x, int y, t_data *vars);
int		key_commands_julia(int key, t_data *vars);
void	ft_julia(t_data vars);
void	draw_julia(t_data *vars);
int		div_julia(int x, int y, t_data *vars);
void	prot_pixel(int x, int y, unsigned int color, t_data *vars);

#endif