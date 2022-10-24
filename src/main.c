/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:44:38 by nlorion           #+#    #+#             */
/*   Updated: 2022/10/24 16:54:42 by nlorion          ###   ########.fr       */
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
    if (ac < 2)
        exit (0);
    init_value(data);
    check_arg(data, av);
    get_complex_values(data);
    screen_display(data);
    image_display(data);
    render(data);
    mlx_key_hook(data->win, keymove, data);
    mlx_mouse_hook(data->win, keymouse, data);
    mlx_hook(data->win, 17, 0, &close_hook, data);
    mlx_hook(data->win, 2, 1L<<0, keypressed, data);
    // printf("main : test1\n");
    mlx_loop(data->ptr);
    clear_all(data);
    free(data);
    return (0);
}
