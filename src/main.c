/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:44:38 by nlorion           #+#    #+#             */
/*   Updated: 2022/10/18 16:26:03 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../include/keysym.h"

int main(int ac, char **av)
{
    t_fractol   *data;
    t_gen   *val;
    t_image *mlx;
    
    data = malloc(sizeof(t_fractol));
    val = malloc(sizeof(t_gen));
    mlx = malloc(sizeof(t_image));
    if (!data || !val || !mlx)
        return (0);
    init_value(data, val, mlx, av);
    screen_display(data);
    if (ac != 2)
        exit (0);
    image_display(data);
    set_mandelbrot(data);
    mlx_hook(data->win, 2, 1L<<0, &keypressed, data);
    mlx_hook(data->win, 17, 0, &close_hook, data);
    // mlx_mouse_hook(data.win, &keymouse, &data);
    mlx_loop(data->ptr);
    clear_all(data);
    free(data->av);
    return (0);
}

/*
    - Gérer la modulation des motifs de julia via les arguments av[2] av[3]
    - Gérer le zoom de la souris en fonction de la position du pointeur
*/