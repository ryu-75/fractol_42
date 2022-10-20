/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 11:31:19 by nlorion           #+#    #+#             */
/*   Updated: 2022/10/20 14:07:53 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void    init_value(t_fractol *data, char **av)
{
    data->gen.x = 0;
    data->gen.y = 0;
    data->gen.zi = 0;
    data->gen.zr = 0;
    data->gen.pr = 0;
    data->gen.pi = 0;
    data->gen.tmp = 0;
    data->mlx_img.size_line = 0;
    data->mlx_img.bpp = 0;
    data->mlx_img.endian = 1;
    data->av = av;
    data->min_rx = 0;
    data->min_iy = 0;
    data->max_rx = 0;
    data->max_iy = 0;
    data->h = 900;
    data->w = 900;
}

int check_set(char *av, char *set)
{
    int i;

    i = 0;
    while (set[i])
    {
        if (av[i] == set[i])
            return (1);
        i++;
    }
    return (0);
}

void    print_arg()
{
    ft_putstr_fd("Expected: ./fractol mandelbrot\n", 2);
    ft_putstr_fd("Expected: ./fractol julia\n", 2);
}

int check_arg(t_fractol *data)
{
    int size;

    size = ft_strlen(data->av[1]);
    if ((data->av)[1] && !ft_strncmp((data->av)[1], "mandelbrot", 10) && size == 10)
        return (0);
    else if ((data->av)[1] && !ft_strncmp((data->av)[1], "julia", 5) && size == 5)
        return (1);
    else
    {
        ft_putstr_fd("Error: Invalid arguments\n", 2);
        print_arg();
        exit(0);
    }
    return (0);
}

double  ft_atod(const char *nptr)
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
		result = result * 10 + *nptr - '0';
		nptr++;
	}
	return (result * sign);
}

