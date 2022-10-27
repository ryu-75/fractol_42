/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:12:12 by nlorion           #+#    #+#             */
/*   Updated: 2022/10/27 12:02:33 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../include/keysym.h"

void    complex_julia(t_fractol *data, int keysym)
{
    if (keysym == F1)
    {
        data->zr = -0.9966667;
        data->zi = 0.0066667;
    }
    else if (keysym == F2)
    {
        data->zr = -0.1200;
        data->zi = 0.7700;
    }
    else if (keysym == F3)
    {
        data->zr = 0.315;
        data->zi = 0.015;       
    }
    else if (keysym == F4)
    {
        data->zr = -0.737;
        data->zi = 0.102;
    }
}