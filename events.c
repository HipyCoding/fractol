/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 03:59:46 by candrese          #+#    #+#             */
/*   Updated: 2024/05/02 14:22:06 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	close_window(t_fractol *f)
{
	mlx_delete_image(f->mlx, f->img);
	mlx_close_window(f->mlx);
	mlx_terminate(f->mlx);
	exit(EXIT_SUCCESS);
}

void	input(mlx_key_data_t input, void *param )
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	if (input.key == MLX_KEY_ESCAPE && input.action == MLX_PRESS)
		close_window(fractol);
	else if (input.key == MLX_KEY_UP && input.action == MLX_PRESS)
		move_up(fractol);
	else if (input.key == MLX_KEY_DOWN && input.action == MLX_PRESS)
		move_down(fractol);
	else if (input.key == MLX_KEY_LEFT && input.action == MLX_PRESS)
		move_left(fractol);
	else if (input.key == MLX_KEY_RIGHT && input.action == MLX_PRESS)
		move_right(fractol);
	else if (input.key == MLX_KEY_1 && input.action == MLX_PRESS)
		fractol->color_scheme = 1;
	else if (input.key == MLX_KEY_2 && input.action == MLX_PRESS)
		fractol->color_scheme = 2;
	else if (input.key == MLX_KEY_3 && input.action == MLX_PRESS)
		fractol->color_scheme = 3;
	else
		return ;
	put_fractal (fractol);
}

// small explanation because zoom function is hard to understand:
// x = f->x_min + ((double)f->mouse_x / WIDTH) * (f->x_max - f->x_min);
// above step converts mouseposition to a coordinate within the fractal space
// x_range = (f->x_max - f->x_min) / f->zoom;
// converts old range to new range for narrowing or stretching of the fractal
// f->x_min = x - ((double)f->mouse_x / WIDTH) * x_range;
// x coordinate of mouse position subtracted by ( %factor * new range) for new xmin
// after that we update the rest of the fractal window-boundaries

void	zoom(double xdelta, double ydelta, void *param)
{
	double		x;
	double		y;
	double		x_range;
	double		y_range;
	t_fractol	*f;

	xdelta = 0;
	f = (t_fractol *)param;
	mlx_get_mouse_pos(f->mlx, &f->mouse_x, &f->mouse_y);
	x = f->x_min + ((double)f->mouse_x / WIDTH) * (f->x_max - f->x_min);
	y = f->y_min + ((double)f->mouse_y / HEIGHT) * (f->y_max - f->y_min);
	if (ydelta > 0)
		f->zoom = 1 / f->zoom;
	x_range = (f->x_max - f->x_min) / f->zoom;
	y_range = (f->y_max - f->y_min) / f->zoom;
	f->x_min = x - ((double)f->mouse_x / WIDTH) * x_range;
	f->x_max = f->x_min + x_range;
	f->y_min = y - ((double)f->mouse_y / HEIGHT) * y_range;
	f->y_max = f->y_min + y_range;
	f->zoom = 1.4;
	put_fractal(f);
}
