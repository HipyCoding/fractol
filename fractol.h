/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:59:45 by candrese          #+#    #+#             */
/*   Updated: 2024/05/02 14:31:30 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <math.h>
# include "lib/MLX42/include/MLX42/MLX42.h"

# ifndef HEIGHT
#  define HEIGHT 1000
# endif

# ifndef WIDTH
#  define WIDTH 1000
# endif

# define MENU_MESSAGE "\n\t keybinds: \n\t\t >esc< to exit \n\t\t >arrow keys< to move \n\t\t >mouse wheel<\
 to zoom \n\t\t >1/2/3< for color scheme psychadelic/warm/epileptic\n\n"

# define ERROR_MESSAGE "\n\t incorrect arguments, please type: \n\t\t ./fractol mandelbrot \n\t\t ./fractol\
 julia (optional)real (optional)imaginary \n\t\t ./fractol ship \n\n"

typedef struct s_fractol
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	char			*set;
	double			x_max;
	double			y_max;
	double			x_min;
	double			y_min;
	int32_t			mouse_x;
	int32_t			mouse_y;
	int				x;
	int				y;
	double			zy;
	double			zx;
	double			cy;
	double			cx;
	double			j_cy;
	double			j_cx;
	double			zoom;
	int				max_iter;
	int				iter;
	int				r;
	int				g;
	int				b;
	int				color_scheme;
}	t_fractol;

//utility
double			atod(char *str);
int				ft_atoi(const char *str);
double			absolute(double nb);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			putstr_fd(char *s, int fd);

//calculation and drawing of fractals
int				mandelbrot_burningship(t_fractol *f);
int				julia(t_fractol *f);
void			put_fractal(t_fractol	*f);
void			init_to_winit(t_fractol *fractol);

//handling of pixel colors
int				ft_color(t_fractol *f);
int32_t			ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);

//input and events
void			input(mlx_key_data_t key, void *param);
void			move_up(t_fractol *f);
void			move_down(t_fractol *f);
void			move_left(t_fractol *f);
void			move_right(t_fractol *f);
void			zoom(double xdelta, double ydelta, void *param);

#endif
