/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:59:36 by nlorion           #+#    #+#             */
/*   Updated: 2022/10/27 00:20:32 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

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
