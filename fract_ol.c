/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 13:07:29 by rkawahar          #+#    #+#             */
/*   Updated: 2024/06/11 14:18:10 by rkawahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

char	*re_create(char *str, char tmp)
{
	int		len;
	int		i;
	char	*ans;

	len = ft_strlen(str);
	ans = (char *)malloc(len + 2);
	if (ans == NULL)
		exit(1);
	i = 0;
	while (str[i])
	{
		ans[i] = str[i];
		i++;
	}
	ans[i] = tmp;
	ans[i + 1] = '\0';
	free(str);
	return (ans);
}

char	*ft_gnl(void)
{
	char	tmp;
	char	*ans;
	int		read_byte;

	tmp = '\0';
	ans = (char *)malloc(1);
	if (ans == NULL)
		exit(1);
	ans[0] = '\0';
	while (tmp != '\n')
	{
		read_byte = read(1, &tmp, 1);
		if (read_byte < 0)
			ft_perror();
		ans = re_create(ans, tmp);
	}
	return (ans);
}

int	main(void)
{
	char	*str;
	t_data	*vars;

	vars = (t_data *)malloc(sizeof(t_data));
	str = (char *)malloc(1);
	if (str == NULL)
		exit(1);
	str[0] = '\0';
	while (ft_strncmp(str, "Julia\n", 6) && ft_strncmp(str, "Mandelbrot\n", 11))
	{
		write(1, "Select and write Julia or Mandelbrot\n", 37);
		write(1, "> ", 2);
		free(str);
		str = ft_gnl();
	}
	ft_mlx(vars);
	if (ft_strncmp(str, "Julia\n", 6) == 0)
		ft_julia();
	else
		ft_mandelbrot(vars);
	free(str);
}

__attribute__((destructor))
static void destructor() {
    system("leaks -q a.out");
}