/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:09:16 by nlorion           #+#    #+#             */
/*   Updated: 2022/10/29 14:52:23 by nlorion          ###   ########.fr       */
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
        ft_key_zoom(data, 0.05, ZOOM);
    else if (keysym == DEZOOM)
        ft_key_zoom(data, 0.05, DEZOOM);
    complex_julia(data, keysym);
    change_fractal(data, keysym);
    render(data);
    printf("%d\n", keysym);
    return (0);
}

int keymouse(int keysym, int x, int y, t_fractol *data)
{
    if (keysym == MOUSE_DOWN)
    {
        ft_mouse_zoom(data, 0.05, MOUSE_DOWN);
        x -= data->w / 2;
        y -= data->h / 2;
        if (x > 0)
            move(data, (double)x / data->w, 'R');
        else if (x < 0)
            move(data, (double)x * -1 / data->w, 'L');
        if (y < 0)
            move(data, (double)y / data->h, 'D');
        else if (y > 0)
            move(data, (double)y * -1 / data->h, 'U');    
    }
    else if (keysym == MOUSE_UP)
        ft_mouse_zoom(data, 0.05, MOUSE_UP);
    render(data);
    return (1);
}
