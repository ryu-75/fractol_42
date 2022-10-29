/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:40:21 by nlorion           #+#    #+#             */
/*   Updated: 2022/10/29 15:01:35 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../include/keysym.h"

static int  add_pixel(t_fractol *data, int x, int y, int color)
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
        data->rgb[2] = (color) & 0xFF;
        data->rgb[1] = (color >> 8) & 0xFF;
        data->rgb[0] = (color >> 16) & 0xFF;
    }
    return (color);
}

void    set_first_color(t_fractol *data, int x, int y, int n)
{
    int colors;
    int rgb[MAX_ITERATION];
    
    data->p_color = rgb;
    colors = WHITE * n / 16 + BLUE + PINK - PINK;
    if (n == MAX_ITERATION)
        data->p_color[1] = add_pixel(data, x, y, BLACK);
    else if (n >= 0 && n <= MAX_ITERATION - 1)
        data->p_color[2] = add_pixel(data, x, y, colors);
}

void    set_second_color(t_fractol *data, int x, int y, int n)
{
    int colors;
    int rgb[MAX_ITERATION];
    
    data->p_color = rgb;
    colors = (BLUE + BLACK) * n / MAX_ITERATION / 4  + BLACK;
    if (n == MAX_ITERATION)
        data->p_color[1] = add_pixel(data, x, y, BLACK);
    else if (n >= 0 && n < MAX_ITERATION)
        data->p_color[2] = add_pixel(data, x, y, colors);
}

// void    color_shift(t_fractol *data, int x, int y, int n)