/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:51:24 by nlorion           #+#    #+#             */
/*   Updated: 2022/11/02 17:08:23 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static int	error_value(t_fractol *data)
{
	if (!check_value(data->av[2]) || !check_value(data->av[3]))
	{
		ft_putstr_fd(">>>Take only numbers<<<\n", 2);
		ft_putstr_fd("Try : -0.9966667 0.0066667\n", 2);
		return (1);
	}
	else if (!ft_strchr(data->av[2], '.') || !ft_strchr(data->av[3], '.'))
	{
		ft_putstr_fd(">>>Expected a double<<<\n", 2);
		ft_putstr_fd("Try : -0.9966667 0.0066667\n", 2);
		return (2);
	}
	return (0);
}

void	print_arg(void)
{
	ft_putstr_fd("Expected: ./fractol mandelbrot\n", 2);
	ft_putstr_fd("Expected: ./fractol julia\n", 2);
	ft_putstr_fd("Expected: ./fractol burning ship\n", 2);
}

static int	len_num(t_fractol *data)
{
	if (ft_atof(data->av[2]) > 2.0 || ft_atof(data->av[2]) < -2.0)
	{
		ft_putstr_fd(">>>Value can be inferior of -2 or superior of 2<<<\n", 2);
		ft_putstr_fd("Try : -0.9966667 0.0066667\n", 2);
		return (1);
	}
	if (ft_atof(data->av[3]) > 2.0 || ft_atof(data->av[3]) < -2.0)
	{
		ft_putstr_fd(">>>Value can be inferior of -2 or superior of 2<<<\n", 2);
		ft_putstr_fd("Try : -0.9966667 0.0066667\n", 2);
		return (2);
	}
	return (0);
}

void	return_error(t_fractol *data)
{	
	if (data->ac < 2 || data->ac > 4)
	{
		print_arg();
		clean_all(data);
		exit (0);
	}
	else if (error_value(data) != 0)
	{
		clean_all(data);
		exit (0);
	}
	else if (len_num(data) != 0)
	{
		clean_all(data);
		exit (0);
	}
}
