/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:12:12 by nlorion           #+#    #+#             */
/*   Updated: 2022/10/25 12:20:47 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../include/keysym.h"

void    get_complex_values(t_fractol *data)
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
        data->zr = -0.9966667;
        data->zi = 0.0066667;
    }
    else if (data->fractal == BURNING_SHIP)
    {
        data->min_rx = -2.5;
        data->max_rx = 1;
        data->min_iy = -1;
        data->max_iy = 1;
    }
}

void    complex_julia(t_fractol *data, int keysym)
{
    if (keysym == F1)
    {
        data->zr = -0.9966667;
        data->zi = 0.0066667;
    }
    else if (keysym == F2)
    {
        data->zr = -0.1200;
        data->zi = 0.7700;
    }
    else if (keysym == F3)
    {
        data->zr = 0.315;
        data->zi = 0.015;       
    }
    else if (keysym == F4)
    {
        data->zr = -0.737;
        data->zi = 0.102;
    }
}