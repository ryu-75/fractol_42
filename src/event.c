/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:09:16 by nlorion           #+#    #+#             */
/*   Updated: 2022/10/18 18:26:49 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../include/keysym.h"

int close_hook(t_fractol *data)
{
    mlx_loop_end(data->ptr);
    return (0);
}

int no_event(t_fractol *data)
{
    (void) data;
    return (0);
}

int keypressed(int keysym, t_fractol *data)
{
    if (keysym == XK_Escape)
    {
        mlx_loop_end(data->ptr);
        return (0);
    }
    else if (keysym == ZOOM)
        ft_zoom(data, 0.5);
    else if (keysym == DEZOOM)
        ft_zoom(data, 1.2);
    else if (keysym == KEY_UP)
        move(data, -0.08, 'U');
    else if (keysym == KEY_DOWN)
        move(data, -0.08, 'D');
    else if (keysym == KEY_LEFT)
        move(data, -0.08, 'L');
    else if (keysym == KEY_RIGHT)
        move(data, -0.08, 'R');
    // if (keysym == TOUCH_1 || keysym == TOUCH_2)
    // {
    //     change_fractal(int keysym, t_fractol *data, char **av);
    //     return (0);
    // }
    printf("%f\n", data->max_rx);
    render(data);
    return (0);
}

int keymouse(int keysym, t_fractol *data, int x, int y)
{
    if (keysym == MOUSE_UP)
    {
            ft_zoom(data, 0.5);
            x -= WIDTH / 2;
            y -= HEIGHT / 2;
            if (x < 0)
                move(data, (double)x * -1 / WIDTH, 'L');
            else if (x > 0)
                move(data, (double)x / WIDTH, 'R');
            if (y < 0)
                move(data, (double)y * -1 / HEIGHT, 'U');
            else if (y > 0)
                move(data, (double)y / HEIGHT, 'D');
    }
    else if (keysym == MOUSE_DOWN)
        ft_zoom(data, 1.2);
    render(data);
    return (0);
}

void    clear_all(t_fractol *data)
{
    mlx_destroy_image(data->ptr, data->mlx_img.img);
    mlx_destroy_window(data->ptr, data->win);
    mlx_destroy_display(data->ptr);
    free(data->ptr);
}
