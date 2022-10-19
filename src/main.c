/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:44:38 by nlorion           #+#    #+#             */
/*   Updated: 2022/10/19 15:55:27 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../include/keysym.h"

int main(int ac, char **av)
{
    t_fractol   *data;

    data = malloc(sizeof(*data));
    if (!data)
        return (0);
    init_value(data, av);
    screen_display(data);
    if (ac != 2)
        exit (0);
    image_display(data);
    render(data);
    mlx_hook(data->win, 17, 0, &close_hook, data);
    mlx_key_hook(data->win, keypressed, data);
    // mlx_mouse_hook(data->win, &keymouse, data);
    mlx_loop(data->ptr);
    clear_all(data);
    free(data);
    return (0);
}
