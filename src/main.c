/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:44:38 by nlorion           #+#    #+#             */
/*   Updated: 2022/10/29 15:16:45 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void    catch_cursor_pos(int x, int y, t_fractol *data)
{
    x -= data->w / 2;
    y -= data->h / 2;
    if (x < 0)
        printf("x < 0 = %d\n", x);
    else if (x > 0)
        printf("x > 0 = %d\n", x);
    if (y < 0)
        printf("y < 0 = %d\n", y);
    else if (y > 0)
        printf("y > 0 = %d\n", y);
    mlx_mouse_get_pos(data->ptr, data->win, &x, &y);
}

int main(int ac, char **av)
{
    t_fractol   *data;

    data = malloc(sizeof(*data));
    if (!data)
        return (0);
    if (ac < 2 || ac > 4)
    {
        ft_putstr_fd(">>>Can have less 2 arguments or more 4 arguments<<<\n", 2);
        exit (0);
    }
    init_value(data, av, ac);
    check_arg(data, av);
    init_complex(data);
    screen_display(data);
    image_display(data);
    render(data);
    mlx_key_hook(data->win, keymove, data);
    mlx_mouse_hook(data->win, keymouse, data);
    mlx_hook(data->win, 17, 0, &close_hook, data);
    mlx_hook(data->win, 2, 1L<<0, keypressed, data);
    mlx_loop(data->ptr);
    init_all(data);
    free(data);
    return (0);
}