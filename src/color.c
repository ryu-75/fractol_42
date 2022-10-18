/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:40:21 by nlorion           #+#    #+#             */
/*   Updated: 2022/10/18 17:15:11 by nlorion          ###   ########.fr       */
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
        color = 0xFF << 24 | colors.rgb[2] << 16 | colors.rgb[1] << 8 | colors.rgb[0];
    }
    else
    {
        colors.rgb[0] = (color) & 0xFF;         // b
        colors.rgb[1] = (color >> 8) & 0xFF;    // g
        colors.rgb[2] = (color >> 16) & 0xFF;   // r
        color = 0xFF << 24 | colors.rgb[2] << 16 | colors.rgb[1] << 8 | colors.rgb[0];
    }
    return (color);
}

void    set_color(t_fractol *data, int x, int y, int n)
{
    int blue;
    int rgb[MAX_ITERATION];
    t_color color;
    
    color.p_color = rgb;
    blue = (BLUE - BLACK) * n / MAX_ITERATION / 6 + BLACK;
    if (n == MAX_ITERATION)
        color.p_color[n] = add_pixel(data, x, y, BLACK);
    else if (n > MAX_ITERATION / 2 && n < MAX_ITERATION - 1)
        color.p_color[n + 1] = add_pixel(data, x, y, WHITE);
    else if (n >= 0 && n <= MAX_ITERATION / 2 - 1)
        color.p_color[n + 2] = add_pixel(data, x, y, blue >> 6);
}

// void    set_color_shift(t_fractol *data, int x, int y, int n, int keysym)
// {
//     int blue;
//     int prune;
//     int rgb[MAX_ITERATION];
//     t_color color;
    
//     color.p_color = rgb;
//     blue = (BLUE - BLACK) * n / MAX_ITERATION / 6 + BLACK;
//     prune = (PRUNE - BLACK) * n / MAX_ITERATION / 64 + PRUNE;
//     if (keysym == SHIFT_1)
//     {
//         if (n == MAX_ITERATION)
//             color.p_color[n] = add_pixel(data, x, y, BLACK);
//         else if (n > 0 && n < MAX_ITERATION)
//             color.p_color[n + 1] = add_pixel(data, x, y, prune);
//     }
//     else if (keysym == SHIFT_2)
//     {
//         if (n == MAX_ITERATION)
//             color.p_color[n] = add_pixel(data, x, y, BLACK);
//         else if (n > MAX_ITERATION / 2 && n < MAX_ITERATION - 1)
//             color.p_color[n + 1] = add_pixel(data, x, y, WHITE);
//         else if (n >= 0 && n <= MAX_ITERATION / 2 - 1)
//             color.p_color[n + 2] = add_pixel(data, x, y, blue >> 6);
//     }
// }