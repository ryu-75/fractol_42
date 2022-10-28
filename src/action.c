/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:41:51 by nlorion           #+#    #+#             */
/*   Updated: 2022/10/28 11:58:24 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../include/keysym.h"

void    ft_mouse_zoom(t_fractol *data, double zoom, int keysym)
{
    if (keysym == MOUSE_DOWN)
    {   
        data->ci = data->min_iy - data->max_iy;
        data->cr = data->min_rx - data->max_rx;
        data->max_rx += (data->cr + zoom * data->cr) / 3 * zoom;
        data->min_rx -= (zoom * data->cr);
        data->min_iy -= (zoom * data->ci);
        data->max_iy += (data->ci + zoom * data->ci) / 3 * zoom;
    }
    else if (keysym == MOUSE_UP)
    {     
        data->ci = data->min_iy - data->max_iy;
        data->cr = data->min_rx - data->max_rx;
        data->max_rx -= (data->cr + zoom * data->cr) / 3 * zoom;
        data->min_rx += (zoom * data->cr);
        data->min_iy += (zoom * data->ci);
        data->max_iy -= (data->ci + zoom * data->ci) / 3 * zoom;
    }
}

void    ft_key_zoom(t_fractol *data, double zoom, int keysym)
{
    if (keysym == ZOOM)
    {
        data->ci = data->min_iy - data->max_iy;
        data->cr = data->min_rx - data->max_rx;
        data->max_rx += (data->cr - zoom * data->cr) / 3 * zoom;
        data->min_rx -= zoom * data->cr;
        data->min_iy -= zoom * data->ci;
        data->max_iy += (data->ci - zoom * data->ci) / 3 * zoom;
    }
    else if (keysym == DEZOOM)
    {
        data->ci = data->min_iy - data->max_iy;
        data->cr = data->min_rx - data->max_rx;
        data->max_rx -= (data->cr - zoom * data->cr) / 3 * zoom;
        data->min_rx += zoom * data->cr;
        data->min_iy += zoom * data->ci;
        data->max_iy -= (data->ci - zoom * data->ci) / 3 * zoom;
    }
}

void    move(t_fractol *data, double move, char movement)
{
    data->ci = data->min_rx - data->max_rx;
    data->cr = data->max_iy - data->min_iy;
    if (movement == 'L')
    {
        data->max_rx -= data->cr * move / 2;
        data->min_rx -= data->cr * move / 2;
    }
    else if (movement == 'R')
    {
        data->max_rx += data->cr * move / 2;
        data->min_rx += data->cr * move / 2;
    }
    if (movement == 'D')
    {
        data->max_iy -= data->ci * move / 2;
        data->min_iy -= data->ci * move / 2;
    }
    else if (movement == 'U')
    {
        data->max_iy += data->ci * move / 2;
        data->min_iy += data->ci * move / 2;
    }
}