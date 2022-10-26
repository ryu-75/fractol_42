/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:41:51 by nlorion           #+#    #+#             */
/*   Updated: 2022/10/27 00:20:49 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../include/keysym.h"

void    ft_zoom(t_fractol *data, double zoom)
{
    double  ci;
    double  cr;

    ci = data->min_iy - data->max_iy;
    cr = data->min_rx - data->max_rx;
    data->max_rx += (cr - zoom * cr) / 2;
    data->min_rx += zoom * cr;
    data->min_iy += zoom * ci;
    data->max_iy += (ci - zoom * ci) / 2;
}

void    mouse_move(t_fractol *data, int x, int y, double move)
{
    double  ci;
    double  cr;
    
    ci = data->min_rx - data->max_rx;
    cr = data->max_iy - data->min_iy;
    if (x < 0)
    {
        data->max_rx -= cr * move;
        data->min_rx -= cr * move;
    }
    else if (x > 0)
    {
        data->max_rx += cr * move;
        data->min_rx += cr * move;
    }
    if (y < 0)
    {
        data->max_iy -= ci * move;
        data->min_iy -= ci * move;
    }
    else if (y > 0)
    {
        data->max_iy += ci * move;
        data->min_iy += ci * move;
    }
}

void    move(t_fractol *data, double move, char movement)
{
    double  ci;
    double  cr;
    
    ci = data->min_rx - data->max_rx;
    cr = data->max_iy - data->min_iy;
    if (movement == 'L')
    {
        data->max_rx -= cr * move / 4;
        data->min_rx -= cr * move / 4;
    }
    else if (movement == 'R')
    {
        data->max_rx += cr * move / 4;
        data->min_rx += cr * move / 4;
    }
    if (movement == 'D')
    {
        data->max_iy -= ci * move / 4;
        data->min_iy -= ci * move / 4;
    }
    else if (movement == 'U')
    {
        data->max_iy += ci * move / 4;
        data->min_iy += ci * move / 4;
    }
}