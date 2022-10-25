/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:44:38 by nlorion           #+#    #+#             */
/*   Updated: 2022/10/25 15:14:33 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../include/keysym.h"

int test(int keysym, int x, int y, t_fractol *data)
{
    (void) data;
    
    x -= data->w / 2;
    y -= data->h / 2;
    if (keysym == MOUSE_DOWN)
        printf("x = %d\ny = %d\n", x, y);
    else if (keysym == MOUSE_UP)
        printf("x = %d\ny = %d\n", x, y);
    return (1);
}

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
    mlx_loop(data->ptr);
    clear_all(data);
    free(data);
    return (0);
}
