/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:44:38 by nlorion           #+#    #+#             */
/*   Updated: 2022/11/02 17:08:09 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main(int ac, char **av)
{
	t_fractol	*data;

	data = malloc(sizeof(*data));
	if (!data)
		return (0);
	init_value(data, av, ac);
	if (ac < 2 || ac > 4)
	{
		ft_putstr_fd(">>>Need at least 2 arguments<<<\n", 2);
		return_error(data);
	}
	check_arg(data, av);
	init_complex(data);
	screen_display(data);
	image_display(data);
	render(data);
	mlx_key_hook(data->win, keymove, data);
	mlx_mouse_hook(data->win, keymouse, data);
	mlx_hook(data->win, 17, 0, close_hook, data);
	mlx_hook(data->win, 2, 1L << 0, keypressed, data);
	mlx_loop(data->ptr);
	init_all(data);
	clean_all(data);
	return (0);
}
