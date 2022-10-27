/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 11:31:19 by nlorion           #+#    #+#             */
/*   Updated: 2022/10/27 14:17:37 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void    print_arg()
{
    ft_putstr_fd("Expected: ./fractol mandelbrot\n", 2);
    ft_putstr_fd("Expected: ./fractol julia\n", 2);
    ft_putstr_fd("Expected: ./fractol burning ship\n", 2);
}

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

double  ft_atof(const char *nptr)
{
	double	result;
	double	sign;

	sign = 1.0;
	result = 0.0;
	while (*nptr == 32 || (*nptr >= 7 && *nptr <= 13))
		nptr++;
	if (*nptr == '-')
	{
		sign = -0.1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10.0 + *nptr - '0';
		nptr++;
	}
	return (result * sign);
}

void	print_prog()
{
	
}