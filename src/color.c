/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:40:21 by nlorion           #+#    #+#             */
/*   Updated: 2022/10/26 14:29:04 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../include/keysym.h"

int add_pixel(t_fractol *data, int x, int y, int color)
{
    data->rgb = data->mlx_img.addr + (y * data->mlx_img.size_line + x * data->mlx_img.bpp / 8); 
    if (data->mlx_img.endian == 0)
    {
        data->rgb[0] = (color) & 0xFF;
        data->rgb[1] = (color >> 8) & 0xFF;
        data->rgb[2] = (color >> 16) & 0xFF;
    }
    else if (data->mlx_img.endian == 1)
    {
        data->rgb[2] = (color) & 0xFF;         // b
        data->rgb[1] = (color >> 8) & 0xFF;    // g
        data->rgb[0] = (color >> 16) & 0xFF;   // r
    }
    return (color);
}

void    set_color(t_fractol *data, int x, int y, int n)
{
    int blue;
    int yellow;
    int rgb[MAX_ITERATION];
    t_color color;

    color.p_color = rgb;
    blue = WHITE * n / 32 * 8 + BLUE;
    yellow = WHITE * n / 24 + YELLOW + WHITE;
    if (n == MAX_ITERATION)
        color.p_color[n + 1] = add_pixel(data, x, y, BLACK);
    else if (n >= MAX_ITERATION / 2 && n <= MAX_ITERATION - 1)
        color.p_color[n + 2] = add_pixel(data, x, y, yellow);
    else if (n >= 0 && n < MAX_ITERATION / 2 - 1)
        color.p_color[n + 3] = add_pixel(data, x, y, blue);
}