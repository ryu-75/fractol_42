/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:45:25 by nlorion           #+#    #+#             */
/*   Updated: 2022/10/18 16:16:02 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../include/keysym.h"

// This value allow to generate mandelbrot
int mandelbrot_value(t_fractol *data, t_gen *val)
{
    int n;

    n = -1;
    data->min_rx = -2.0;
    data->max_rx = 1;
    data->min_iy = -1.5;
    data->max_iy = data->min_iy + (data->max_rx - data->min_rx);
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
    return (1);
}

// This value allow to generate julia 
int julia_value(t_fractol *data, t_gen *val)
{
    int n;

    n = -1;
    data->min_rx = -2.0;
    data->max_rx = 2;
    data->min_iy = -2.0;
    data->max_iy = data->min_iy + (data->max_rx - data->min_rx);
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
    return (1);
}

int set_fractal(t_fractol *data)
{
    int size;

    size = ft_strlen(data->av[1]);
    if ((data->av)[1] && !ft_strncmp((data->av)[1], "mandelbrot", 10) && size == 10)
        data->fractal = 0;
    else if ((data->av)[1] && !ft_strncmp((data->av)[1], "julia", 5) && size == 5)
        data->fractal = 1;
    else
    {
        ft_putstr_fd("Error: Invalid arguments\n", 2);
        print_arg();
        exit(0);
    }
    return (0);
}

int set_mandelbrot(t_fractol *data)
{
    t_gen val;
    
    data->fractal = set_fractal(data);
    val.y = -1;
    while (++val.y <= HEIGHT)
    {
        val.x = -1;
        while (++val.x <= WIDTH)
        {
            if (data->fractal == 0)
                mandelbrot_value(data, &val);
            else if (data->fractal == 1)
                julia_value(data, &val);
        }
    }
    mlx_put_image_to_window(data->ptr, data->win, data->mlx_img.img, 0, 0);
    return (0);
}

int render(t_fractol *data)
{
    t_gen val;
    
    val.y = -1;
    mlx_clear_window(data->ptr, data->win);
    while (++val.y <= HEIGHT)
    {
        val.x = -1;
        while (++val.x <= WIDTH)
        {
            if (set_fractal(data) == 0)
                mandelbrot_value(data, &val);
            else if (set_fractal(data) == 1)
                julia_value(data, &val);
        }
    }
    mlx_put_image_to_window(data->ptr, data->win, data->mlx_img.img, 0, 0);
    return (0);
}