/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 11:31:19 by nlorion           #+#    #+#             */
/*   Updated: 2022/11/02 16:26:58 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	check_arg(t_fractol *data, char **av)
{
	int	size;

	size = ft_strlen(av[1]);
	if (av[1] && !ft_strncmp(av[1], "mandelbrot", 10) && size == 10)
		data->fractal = MANDELBROT;
	else if (av[1] && !ft_strncmp(av[1], "julia", 5) && size == 5)
		data->fractal = JULIA;
	else if (av[1] &&!ft_strncmp(av[1], "burning ship", 12) && size == 12)
		data->fractal = BURNING_SHIP;
	else
	{
		ft_putstr_fd("Error: Invalid arguments\n", 2);
		print_arg();
		clean_all(data);
		exit(0);
	}
}

double	ft_atof(const char *s)
{
	double	decimal;
	double	fractional;
	int		len;
	int		neg;

	neg = 0;
	if (s[0] == '-')
	{
		neg = 1;
		s++;
	}
	decimal = ft_atoi(s);
	s = ft_strchr(s, '.');
	s++;
	len = ft_strlen(s);
	fractional = ft_atoi(s);
	fractional = pow(10, -len) * fractional;
	decimal += fractional;
	if (neg)
		decimal *= -1;
	return (decimal);
}

int	check_value(char *av)
{
	int	i;

	i = 0;
	while (av[i] != 0)
	{
		if (ft_isalpha(av[i]) == 1)
			return (0);
		i++;
	}
	return (1);
}

void	clean_all(t_fractol *data)
{
	free(data->palette);
	free(data);
}
