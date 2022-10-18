/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:41:51 by nlorion           #+#    #+#             */
/*   Updated: 2022/10/18 14:28:07 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../include/keysym.h"

void    ft_zoom(t_fractol *data, double zoom)
{
    double  cr;
    double  ci;
    
    ci = data->min_iy - data->max_iy;
    cr = data->min_rx - data->max_rx;
    data->max_rx = data->max_rx + (cr - zoom * cr) / 2;
    data->min_rx = data->min_rx + zoom * cr;
    data->min_iy = data->min_iy + zoom * ci;
    data->max_iy = data->max_iy + (ci - zoom * ci) / 2;
}

void    move(t_fractol *data, double move, char movement)
{
    double  cr;
    double  ci;
    
    cr = data->min_rx - data->max_rx;
    ci = data->max_iy - data->min_iy;
    if (movement == 'L')
    {
        data->max_rx -= cr * move;
        data->min_rx -= cr * move;
    }
    else if (movement == 'R')
    {
        data->max_rx += cr * move;
        data->min_rx += cr * move;
    }
    if (movement == 'D')
    {
        data->max_iy -= ci * move;
        data->min_iy -= ci * move;
    }
    else if (movement == 'U')
    {
        data->max_iy += ci * move;
        data->min_iy += ci * move;
    }
}