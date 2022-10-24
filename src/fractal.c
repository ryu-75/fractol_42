/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:45:25 by nlorion           #+#    #+#             */
/*   Updated: 2022/10/24 15:51:05 by nlorion          ###   ########.fr       */
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

void    get_complex_values(t_fractol *data)
{
    if (data->fractal == MANDELBROT)
    {
        // data->zi = 0;
        // data->zr = 0;
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
}

void    select_fractal(t_fractol *data, double pr, double pi)
{
    if (data->fractal == MANDELBROT)
        ft_mandelbrot(data, pr, pi);
    else if (data->fractal == JULIA)
        ft_julia(data, pr, pi);
}

void    render(t_fractol *data)
{
    double  pr;
    double  pi;
    int x;
    int y;

    y = -1;
    mlx_clear_window(data->ptr, data->win);
    while (++y <= data->h)
    {
        x = -1;
        while (++x <= data->w)
        {
            pr = data->min_rx + (double)x * (data->max_rx - data->min_rx) / data->w;
            pi = data->min_iy + (double)y * (data->max_iy - data->min_iy) / data->h;
            select_fractal(data, pr, pi);
            set_color(data, x, y, data->n);
        }
    }
    mlx_put_image_to_window(data->ptr, data->win, data->mlx_img.img, 0, 0);
}