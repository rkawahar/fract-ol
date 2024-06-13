/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:11:12 by rkawahar          #+#    #+#             */
/*   Updated: 2024/06/13 10:11:55 by rkawahar         ###   ########.fr       */
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

int	close_window(t_data *vars)
{
	mlx_destroy_window(vars -> mlx, vars -> win);
	exit(0);
}

t_data	*ft_create_vars(void)
{
	t_data	*ans;

	ans = (t_data *)malloc(sizeof(t_data));
	if (ans == NULL)
		exit(1);
	ans -> frac.center_x = 0;
	ans -> frac.center_y = 0;
	ans -> frac.magni = 1;
	ans -> frac.color_factor = 1;
	return (ans);
}
