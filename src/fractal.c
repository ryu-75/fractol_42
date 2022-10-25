/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:45:25 by nlorion           #+#    #+#             */
/*   Updated: 2022/10/25 12:56:02 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../include/keysym.h"

int ft_mandelbrot(t_fractol *data, double pr, double pi)
{
    data->n = -1;
    data->zr = 0;
    data->zi = 0;
    while (++data->n < MAX_ITERATION && (data->zi * data->zi + data->zr * data->zr) < 4.0)
    {
        data->tmp = 2 * data->zr * data->zi + pi;
        data->zr = data->zr * data->zr - data->zi * data->zi + pr;
        data->zi = data->tmp;
    }
    return (1);
}

int ft_burning_ship(t_fractol *data, double pr, double pi)
{
    data->n = -1;
    data->zr = 0;
    data->zi = 0;
    while (++data->n < MAX_ITERATION && (data->zr * data->zr + data->zi * data->zi) < 4.0)
    {
        data->tmp = data->zr * data->zr - data->zi * data->zi + pi;
        data->zr = 2 * abs((int)data->zr * (int)data->zr) + pr;
        data->zi = data->tmp;
    }
    return (1);
}

int ft_julia(t_fractol *data, double pr, double pi)
{    
    data->n = -1;
    while (++data->n < MAX_ITERATION && (pi * pi + pr * pr) < 4.0)
    {
        data->tmp = 2 * pr * pi + data->zi;
        pr = pr * pr - pi * pi + data->zr;
        pi = data->tmp;
    }
    return (1);
}