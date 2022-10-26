/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:09:16 by nlorion           #+#    #+#             */
/*   Updated: 2022/10/27 00:20:53 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../include/keysym.h"

int close_hook(t_fractol *data)
{
    mlx_loop_end(data->ptr);
    return (0);
}

int keypressed(int keysym, t_fractol *data)
{
    if (keysym == XK_Escape)
        mlx_loop_end(data->ptr);
    return (0);
}

int keymove(int keysym, t_fractol *data)
{
    if (keysym == KEY_UP)
        move(data, 0.5, 'U');
    else if (keysym == KEY_DOWN)
        move(data, 0.5, 'D');
    else if (keysym == KEY_LEFT)
        move(data, 0.5, 'L');  
    else if (keysym == KEY_RIGHT)
        move(data, 0.5, 'R');
    else if (keysym == ZOOM)
        ft_zoom(data, 0.05);
    else if (keysym == DEZOOM)
        ft_zoom(data, 1.2);
    complex_julia(data, keysym);
    change_fractal(data, keysym);
    render(data);
    return (0);
}

int keymouse(int keysym, int x, int y, t_fractol *data)
{
    if (keysym == MOUSE_DOWN)
    {
        ft_zoom(data, 0.05);
        x -= data->w / 2;
        y -= data->h / 2;
        if (x < 0)
            mouse_move(data, x, y, (double)x * -1 / data->w);
        else if (x > 0)
            mouse_move(data, x, y, (double)x / data->w);
        if (y < 0)
            mouse_move(data, x, y, (double)y * -1 / data->h);
        else if (y > 0)
            mouse_move(data, x, y, (double)y / data->h);
    }
    else if (keysym == MOUSE_UP)
        ft_zoom(data, 1.2);
    render(data);
    return (1);
}

void    clear_all(t_fractol *data)
{
    mlx_destroy_image(data->ptr, data->mlx_img.img);
    mlx_destroy_window(data->ptr, data->win);
    mlx_destroy_display(data->ptr);
    free(data->ptr);
}
