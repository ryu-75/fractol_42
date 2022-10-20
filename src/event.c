/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:09:16 by nlorion           #+#    #+#             */
/*   Updated: 2022/10/20 14:11:19 by nlorion          ###   ########.fr       */
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
    {
        move(data, 1.2, 'U');
        render(data);
    }
    else if (keysym == KEY_DOWN)
    {
        move(data, 1.2, 'D');
        render(data);
    }
    else if (keysym == KEY_LEFT)
    {
        move(data, 1.2, 'L');
        render(data);
    }  
    else if (keysym == KEY_RIGHT)
    {
        move(data, 1.2, 'R');
        render(data);
    }
    else if (keysym == ZOOM)
    {
        data->max_rx += data->max_rx + 0.5 * (data->max_rx - data->min_rx);
        data->min_rx += data->max_rx + 0.5 * (data->max_rx - data->min_rx);
        ft_zoom(data, 0.5);
        render(data);
    }
    else if (keysym == DEZOOM)
    {
        ft_zoom(data, 1.2);
        render(data);
    }
    return (0);
}

int keymouse(int keysym, t_fractol *data, int x, int y)
{
    double  scalling;

    scalling = 0;
    // x -= data->w / 2;
    // y -= data->h / 2;
    printf("%d\n", x);
    if (data->w <= x && x >= 0 && data->h <= y && y >= 0)
    {
        if (keysym == MOUSE_DOWN)
        {
            printf("test2\n");
            scalling = 0.5;
            ft_zoom(data, scalling);
            if (x < 0)
                move(data, (double)x * -1 / data->w, 'L');
            else if (x > 0)
                move(data, (double)x / data->w, 'R');
            if (y < 0)
                move(data, (double)y * -1 / data->h, 'U');
            else if (y > 0)
                move(data, (double)y / data->h, 'D');
            render(data);
        }
        else if (keysym == MOUSE_UP)
        {
            printf("test3\n");
            scalling = 1.2;
            ft_zoom(data, scalling);
            render(data);
        }
    }
    return (1);
}

void    clear_all(t_fractol *data)
{
    mlx_destroy_image(data->ptr, data->mlx_img.img);
    mlx_destroy_window(data->ptr, data->win);
    mlx_destroy_display(data->ptr);
    free(data->ptr);
}
