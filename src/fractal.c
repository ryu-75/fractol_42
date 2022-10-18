/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:45:25 by nlorion           #+#    #+#             */
/*   Updated: 2022/10/18 18:18:46 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../include/keysym.h"

void    fractal_value(t_fractol *data)
{
    if (check_arg(data) == 0)
    {
        data->min_rx = -2.0;
        data->max_rx = 1;
        data->min_iy = -1.5;
        data->max_iy = data->min_iy + (data->max_rx - data->min_rx);
    }
    else if (check_arg(data) == 1)
    {
        data->min_rx = -2.0;
        data->max_rx = 2;
        data->min_iy = -2.0;
        data->max_iy = data->min_iy + (data->max_rx - data->min_rx);
    }
}

void    ft_mandelbrot(t_fractol *data, t_gen *val)
{
    int n;

    fractal_value(data);
    n = -1;
    val->zi = 0;
    val->zr = 0;
    val->pr = data->min_rx + (double)val->x * (data->max_rx - data->min_rx) / WIDTH;
    val->pi = data->min_iy + (double)val->y * (data->max_iy - data->min_iy) / HEIGHT;
    while (++n < MAX_ITERATION && (val->zi * val->zi + val->zr * val->zr) < 4.0)
    {
        val->tmp = 2 * val->zr * val->zi + val->pi;
        val->zr = val->zr * val->zr - val->zi * val->zi + val->pr;
        val->zi = val->tmp;
    }
    set_color(data, val->x, val->y, n);
}

// This value allow to generate julia 
void    ft_julia(t_fractol *data, t_gen *val)
{
    int n;

    fractal_value(data);
    n = -1;
    val->kr = -0.9966667;
    val->ki = 0.0066667;
    val->pr = data->min_rx + (double)val->x * (data->max_rx - data->min_rx) / WIDTH;
    val->pi = data->min_iy + (double)val->y * (data->max_iy - data->min_iy) / HEIGHT;
    while (++n < MAX_ITERATION && (val->pi * val->pi + val->pr * val->pr) < 4.0)
    {
        val->tmp = 2 * val->pr * val->pi + val->ki;
        val->pr = val->pr * val->pr - val->pi * val->pi + val->kr;
        val->pi = val->tmp;
    }
    set_color(data, val->x, val->y, n);
}

void    render(t_fractol *data)
{
    t_gen val;
    
    data->fractal = check_arg(data);
    mlx_clear_window(data->ptr, data->win);
    val.y = -1;
    while (++val.y <= HEIGHT)
    {
        val.x = -1;
        while (++val.x <= WIDTH)
        {
            if (data->fractal == 0)
                ft_mandelbrot(data, &val);
            else if (data->fractal == 1)
                ft_julia(data, &val);
        }
    }
    mlx_put_image_to_window(data->ptr, data->win, data->mlx_img.img, 0, 0);
}