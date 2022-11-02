/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:12:12 by nlorion           #+#    #+#             */
/*   Updated: 2022/11/02 17:04:13 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../include/keysym.h"

void	complex_julia(t_fractol *data, int keysym)
{
	if (keysym == KEY_1)
	{
		data->zr = -0.9966667;
		data->zi = 0.0066667;
	}
	else if (keysym == KEY_2)
	{
		data->zr = -0.1200;
		data->zi = 0.7700;
	}
	else if (keysym == KEY_3)
	{
		data->zr = 0.315;
		data->zi = 0.015;
	}
	else if (keysym == KEY_4)
	{
		data->zr = -0.737;
		data->zi = 0.102;
	}
}

static void	set_julia_complex(t_fractol *data)
{
	if ((data->ac < 3) || data->ac == 3)
	{
		ft_putstr_fd(">>>Write your own value to change Julia<<<\n", 2);
		ft_putstr_fd("Ex : -0.9966667 0.0066667\n", 2);
		data->zr = -0.9966667;
		data->zi = 0.0066667;
	}
	else if (data->ac > 2)
	{
		return_error(data);
		data->zr = ft_atof(data->av[2]);
		data->zi = ft_atof(data->av[3]);
	}
}

void	init_complex(t_fractol *data)
{
	if (data->fractal == MANDELBROT)
	{
		data->min_rx = -2.0;
		data->max_rx = 1;
		data->min_iy = -1.5;
		data->max_iy = data->min_iy + (data->max_rx - data->min_rx);
	}
	else if (data->fractal == JULIA)
	{
		data->min_rx = -2.0;
		data->max_rx = 2.0;
		data->min_iy = -2.0;
		data->max_iy = data->min_iy + (data->max_rx - data->min_rx);
		set_julia_complex(data);
	}
	else if (data->fractal == BURNING_SHIP)
	{
		data->min_rx = -2.0;
		data->max_rx = 1;
		data->min_iy = -2;
		data->max_iy = data->min_iy + (data->max_rx - data->min_rx);
	}
}
