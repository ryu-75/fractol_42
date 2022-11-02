/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:40:21 by nlorion           #+#    #+#             */
/*   Updated: 2022/11/02 16:25:34 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../include/keysym.h"

static int	add_pixel(t_fractol *data, int x, int y, int color)
{
	data->rgb = data->mlx_img.addr
		+ (y * data->mlx_img.size_line + x * data->mlx_img.bpp / 8);
	data->rgb[0] = (color) & 0xFF;
	data->rgb[1] = (color >> 8) & 0xFF;
	data->rgb[2] = (color >> 16) & 0xFF;
	return (color);
}

void	set_first_color(t_fractol *data, int x, int y, int n)
{
	init_colours(data);
	if (n == MAX_ITERATION)
		data->p_color = add_pixel(data, x, y, data->palette[0]);
	else
		data->p_color = add_pixel(data, x, y, data->palette[n % 6 + 1]);
}
