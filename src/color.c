/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:40:21 by nlorion           #+#    #+#             */
/*   Updated: 2022/10/20 12:55:13 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../include/keysym.h"
int add_pixel(t_fractol *data, int x, int y, int color)
{
    t_color colors;

    colors.rgb = data->mlx_img.addr + (y * data->mlx_img.size_line + x * data->mlx_img.bpp / 8); 
    if (data->mlx_img.endian == 1)
    {
        colors.rgb[0] = (color) & 0xFF;
        colors.rgb[1] = (color >> 8) & 0xFF;
        colors.rgb[2] = (color >> 16) & 0xFF;
        colors.rgb[3] = (color >> 24) & 0xFF;
    }
    else
    {
        colors.rgb[0] = (color) & 0xFF;         // b
        colors.rgb[1] = (color >> 8) & 0xFF;    // g
        colors.rgb[2] = (color >> 16) & 0xFF;   // r
        colors.rgb[3] = (color >> 24) & 0xFF;   // f
    }
    return (color);
}

void    set_color(t_fractol *data, int x, int y, int n)
{
    int blue;
    int rgb[MAX_ITERATION];
    t_color color;

    color.p_color = rgb;
    blue = WHITE * n / 2 + BLUE + PINK;
    if (n == MAX_ITERATION)
        color.p_color[n] = add_pixel(data, x, y, BLACK);
    else if (n >= 0 && n < MAX_ITERATION / 2)
    {
        color.p_color[n + 2] = add_pixel(data, x, y, blue);
        if (n >= 20 && n < MAX_ITERATION / 2)
            color.p_color[n + 3] = add_pixel(data, x, y, WHITE);
    }
}