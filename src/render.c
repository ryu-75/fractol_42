/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:29:25 by sasha             #+#    #+#             */
/*   Updated: 2022/10/18 14:29:59 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

// int render_shift(t_fractol *data, int keysym)
// {
//     int n;
//     t_gen   val;
    
//     val.y = -1;
//     mlx_clear_window(data->ptr, data->win);
//     while (++val.y <= HEIGHT)
//     {
//         val.x = -1;
//         while (++val.x <= WIDTH)
//         {
//             val.zi = 0;
//             val.zr = 0;
//             n = -1;
//             val.pr = data->min_rx + (double)val.x * (data->max_rx - data->min_rx) / WIDTH;
//             val.pi = data->min_iy + (double)val.y * (data->max_iy - data->min_iy) / HEIGHT;
//             while (++n < MAX_ITERATION && (val.zi * val.zi + val.zr * val.zr) < 4.0)
//             {
//                 val.tmp = 2 * val.zr * val.zi + val.pi;
//                 val.zr = val.zr * val.zr - val.zi * val.zi + val.pr;
//                 val.zi = val.tmp;
//             }
//             set_color_shift(data, val.x, val.y, n, keysym);
//         }
//     }
//     mlx_put_image_to_window(data->ptr, data->win, data->mlx_img.img, 0, 0);
//     return (0);
// }

