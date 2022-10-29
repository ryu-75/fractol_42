/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:01:57 by nlorion           #+#    #+#             */
/*   Updated: 2022/10/29 14:24:36 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void    init_value(t_fractol *data, char **av, int ac)
{
    data->av = av;
    data->ac = ac;
    data->zi = 0;
    data->zr = 0;
    data->tmp = 0;
    data->mlx_img.size_line = 0;
    data->mlx_img.bpp = 0;
    data->mlx_img.endian = -1;
    data->min_rx = 0;
    data->min_iy = 0;
    data->max_rx = 0;
    data->max_iy = 0;
    data->h = 900;
    data->w = 900;
}

void    screen_display(t_fractol *data)
{    
    data->ptr = mlx_init();
    data->win = mlx_new_window(data->ptr, data->w, data->h, "fractol");
    if (data->ptr == NULL || data->win == NULL)
    {
        free(data->ptr);
        exit(MLX_ERROR);
    }
}

void    image_display(t_fractol *data)
{
    data->mlx_img.img = mlx_new_image(data->ptr, data->w, data->h);
    if (data->mlx_img.img == NULL)
        exit (MLX_ERROR);
    data->mlx_img.addr = mlx_get_data_addr(data->mlx_img.img, 
        &data->mlx_img.bpp, &data->mlx_img.size_line, 
            &data->mlx_img.endian);
    if (data->mlx_img.addr == NULL)
    {
        free(data->mlx_img.addr);
        exit (MLX_ERROR);
    }
}

void    init_all(t_fractol *data)
{
    if (data->ptr && data->mlx_img.img)
        mlx_destroy_image(data->ptr, data->mlx_img.img);
    if (data->ptr && data->win)
        mlx_destroy_window(data->ptr, data->win);
    if (data->ptr)
        mlx_destroy_display(data->ptr);
    free(data->ptr);
}
