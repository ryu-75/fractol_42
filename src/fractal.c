/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:45:25 by nlorion           #+#    #+#             */
/*   Updated: 2022/10/20 15:43:11 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../include/keysym.h"

void    fractal_process(t_fractol *data, t_gen *val)
{
    val->pr = data->min_rx + (double)val->x * (data->max_rx - data->min_rx) / data->w;
    val->pi = data->min_iy + (double)val->y * (data->max_iy - data->min_iy) / data->h;
}

void    ft_mandelbrot(t_fractol *data, t_gen *val)
{
    int n;

    n = -1;
    val->zi = 0;
    val->zr = 0;
    data->min_rx = -2.0;
    data->max_rx = 1;
    data->min_iy = -1.5;
    data->max_iy = data->min_iy + (data->max_rx - data->min_rx);
    fractal_process(data, val);
    while (++n < MAX_ITERATION && (val->zi * val->zi + val->zr * val->zr) < 4.0)
    {
        val->tmp = 2 * val->zr * val->zi + val->pi;
        val->zr = val->zr * val->zr - val->zi * val->zi + val->pr;
        val->zi = val->tmp;
    }
    set_color(data, val->x, val->y, n);
}

void    ft_julia(t_fractol *data, t_gen *val)
{
    int n;

    n = -1;
    data->min_rx = -2.0;
    data->max_rx = 2.0;
    data->min_iy = -2.0;
    data->max_iy = data->min_iy + (data->max_rx - data->min_rx);
    val->zr = -0.1224780;
    val->zi = 0.7444300;
    // julias_value(t_fractol, t_gen *val); --> Change zr and zi 
    fractal_process(data, val);
    while (++n < MAX_ITERATION && (val->pi * val->pi + val->pr * val->pr) < 4.0)
    {
        val->tmp = 2 * val->pr * val->pi + val->zi;
        val->pr = val->pr * val->pr - val->pi * val->pi + val->zr;
        val->pi = val->tmp;
    }
    set_color(data, val->x, val->y, n);
}
// data->julia_set = {val->zr, val->zi}

void    julia_value(t_fractol *data, t_gen *val, int keycode)
{   
    if (keycode == TOUCH_1)
        (*data)->julia_set = {-0.1224780, 0.7444300};
}


void    array_function(t_fractol *data, t_gen *val, int id)
{
    void    (*ftptr[2])(t_fractol *, t_gen *);

    ftptr[0] = ft_mandelbrot;
    ftptr[1] = ft_julia;

    ((*ftptr[id])(data, val));
}

void    render(t_fractol *data)
{
    t_gen val;
    
    val.y = -1;
    mlx_clear_window(data->ptr, data->win);
    while (++val.y <= data->h)
    {
        val.x = -1;
        while (++val.x <= data->w)
            array_function(data, &val, check_arg(data));
    }
    mlx_put_image_to_window(data->ptr, data->win, data->mlx_img.img, 0, 0);
}