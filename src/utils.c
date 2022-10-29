/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 11:31:19 by nlorion           #+#    #+#             */
/*   Updated: 2022/10/29 14:58:04 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void    check_arg(t_fractol *data, char **av)
{
    int size;

    size = ft_strlen(av[1]);
    if (av[1] && !ft_strncmp(av[1], "mandelbrot", 10) && size == 10)
        data->fractal = MANDELBROT;
    else if (av[1] && !ft_strncmp(av[1], "julia", 5) && size == 5)
        data->fractal = JULIA;
    else if (av[1] &&!ft_strncmp(av[1], "burning ship", 10) && size == 10)
        data->fractal = BURNING_SHIP;
    else
    {
        ft_putstr_fd("Error: Invalid arguments\n", 2);
        print_arg();
        exit(0);
    }
}

double  ft_atof(const char *s)
{
	double	decimal;
	double	fractional;
	int	len;
	int	neg;

	neg = 0;
	if (s[0] == '-')
	{
		neg = 1;
		s++;
	}
	decimal = ft_atoi(s);
	s = strchr(s, '.');
	s++;
	len = ft_strlen(s);
	fractional = ft_atoi(s);
	fractional = pow(10, -len) * fractional;
	decimal += fractional;
	if (neg)
		decimal *= -1;
	return (decimal);
}

void    print_arg()
{
    ft_putstr_fd("Expected: ./fractol mandelbrot\n", 2);
    ft_putstr_fd("Expected: ./fractol julia\n", 2);
    ft_putstr_fd("Expected: ./fractol burning ship\n", 2);
}

void	error_value(t_fractol *data)
{
	if (!ft_strchr(data->av[2], '.') || !ft_strchr(data->av[3], '.'))
	{
	    ft_putstr_fd(">>>Expected a double<<<\n", 2);
	    ft_putstr_fd("Try : -0.9966667 0.0066667\n", 2);
	    exit (0);
	}
	if (atof(data->av[2]) > 2 || ft_atof(data->av[2]) < -2)
	{
	    ft_putstr_fd(">>>Value can be inferior of -2 or superior of 2<<<\n", 2);
	    ft_putstr_fd("Try : -0.9966667 0.0066667\n", 2);
	    exit (0);
	}
	if (ft_atof(data->av[3]) > 2 || ft_atof(data->av[3]) < -2)
	{
	    ft_putstr_fd(">>>Value can be inferior of -2 or superior of 2<<<\n", 2);
	    ft_putstr_fd("Try : -0.9966667 0.0066667\n", 2);
	    exit (0);
	}	
}