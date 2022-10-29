/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 19:54:50 by nlorion           #+#    #+#             */
/*   Updated: 2022/10/29 14:53:03 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     FRACTOL_H
# define    FRACTOL_H

# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>
# include <math.h>

# define    MAX_ITERATION 200
# define    MLX_ERROR 1
# define    WHITE 0x00FFFFFF
# define    BLACK 0x00000000
# define    BLUE 0x000CAAE8
# define    PINK 0x00E600D6
# define    RED 0x00BD280D
# define    YELLOW 0x00C9A308

typedef enum e_fselect
{
    MANDELBROT,
    JULIA,
    BURNING_SHIP
}           t_fselect;

typedef struct s_image
{
    void    *img;
    char    *addr;
    int size_line;
    int bpp;
    int endian;
}           t_image;

typedef struct  s_fractol
{
    void        *ptr;
    void        *win;
    char    **av;
    int ac;
    double  min_rx;
    double  max_rx;
    double  min_iy;
    double  max_iy;
    double  zi;
    double  zr;
    double  tmp;
    double  cr;
    double  ci;
    char    *rgb;
    int *p_color;
    int w;
    int h;
    int n;
    int fractal;
    t_image mlx_img;
}           t_fractol;


// -------------------- Event ----------------------------- // 
int keypressed(int keysym, t_fractol *data);
int keyrelease(int keysym, t_fractol *data);
int keymove(int keysym, t_fractol *data);
int close_hook(t_fractol *data);
void    close_win(t_fractol *data);

// -------------------- Display --------------------------- //
void    screen_display(t_fractol *data);
void    image_display(t_fractol *data);
void    set_first_color(t_fractol *data, int x, int y, int n);
void    set_second_color(t_fractol *data, int x, int y, int n);
void    init_all(t_fractol *data);

// ------------------------ Utils ------------------------- //
void    print_arg();
void    check_arg(t_fractol *data, char **av);
void    init_value(t_fractol *data, char **av, int ac);
void	error_value(t_fractol *data);

// ---------------------- Action -------------------------- //
void    ft_mouse_zoom(t_fractol *data, double zoom, int keysym);
void    ft_key_zoom(t_fractol *data, double zoom, int keysym);
void    move(t_fractol *data, double move, char movement);
int keymouse(int keysym, int x, int y, t_fractol *data);

// --------------------- Generator ------------------------ //
void    change_fractal(t_fractol *data, int keysym);
void    render(t_fractol *data);
int add_pixel(t_fractol *data, int x, int y, int color);

// --------------------- Fractal -------------------------- //
int ft_mandelbrot(t_fractol *data, double pr, double pi);
int ft_burning_ship(t_fractol *data, double pr, double pi);
int ft_julia(t_fractol *data, double pr, double pi);

// --------------------- Complex value -------------------- //
void    init_complex(t_fractol *data);
void    complex_julia(t_fractol *data, int keysym);
double  ft_atof(const char *s);
#endif