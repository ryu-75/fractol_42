/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 11:31:19 by nlorion           #+#    #+#             */
/*   Updated: 2022/10/18 16:21:33 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void    init_value(t_fractol *data, t_gen *val, t_image *mlx, char **av)
{
    val->x = 0;
    val->y = 0;
    val->zi = 0;
    val->zr = 0;
    val->pr = 0;
    val->pi = 0;
    val->tmp = 0;
    mlx->size_line = 0;
    mlx->bpp = 0;
    mlx->endian = 0;
    data->av = av;
    data->min_rx = 0;
    data->min_iy = 0;
    data->max_rx = 0;
    data->max_iy = 0;
    val->ki = 0;
    val->kr = 0;
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