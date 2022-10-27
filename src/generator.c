/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:13:40 by nlorion           #+#    #+#             */
/*   Updated: 2022/10/27 13:02:17 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../include/keysym.h"

void    change_fractal(t_fractol *data, int keysym)
{
    if (keysym == TOUCH_1)
    {
        data->fractal = MANDELBROT;
        init_complex(data);
    }
    else if (keysym == TOUCH_2)
    {
        data->fractal = JULIA;
        init_complex(data);
    }
    else if (keysym == TOUCH_3)
    {
        data->fractal = BURNING_SHIP;
        init_complex(data);
    }
}

static void select_fractal(t_fractol *data, double pr, double pi)
{
    if (data->fractal == MANDELBROT)
        ft_mandelbrot(data, pr, pi);
    else if (data->fractal == JULIA)
        ft_julia(data, pr, pi);
    else if (data->fractal == BURNING_SHIP)
        ft_burning_ship(data, pr, pi);
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