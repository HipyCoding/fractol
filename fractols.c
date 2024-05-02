/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:31:34 by candrese          #+#    #+#             */
/*   Updated: 2024/04/30 19:17:04 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//x-coordinate (f->cx) is calculated by mapping the current column index 
//(f->x) to a value within the range of the fractal's x-axis
//after that fractol formulars are called on cx and cy representing koordinates;

void	put_fractal(t_fractol	*f)
{
	mlx_delete_image(f->mlx, f->img);
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(f->mlx, f->img, 0, 0);
	f->y = 0;
	while (f->y < HEIGHT)
	{
		f->x = 0;
		while (f->x < WIDTH)
		{
			f->cy = f->y_min + (double)f->y * (f->y_max - f->y_min) / HEIGHT;
			f->cx = f->x_min + ((double)f->x * (f->x_max - f->x_min)) / WIDTH;
			if (!ft_strncmp("j", f->set, 1))
				f->iter = julia(f);
			else
				f->iter = mandelbrot_burningship(f);
			f->x++;
		}
		f->y++;
	}
}

int	mandelbrot_burningship(t_fractol *f)
{
	int		n;
	double	temp;

	n = 0;
	f->zy = 0;
	f->zx = 0;
	while (n < f->max_iter && ((f->zx * f->zx + f->zy * f->zy) < 4.0))
	{
		temp = 2 * f->zx * f->zy + f->cy;
		f->zx = f->zx * f->zx - f->zy * f->zy + f->cx;
		f->zy = temp;
		if (!ft_strncmp("s", f->set, 1))
		{
			f->zx = absolute (f->zx);
			f->zy = absolute (f->zy);
		}
		n++;
	}
	mlx_put_pixel(f->img, f->x, f->y, ft_color(f));
	return (n);
}

int	julia(t_fractol *f)
{
	int		n;
	double	temp;

	n = 0;
	while (n < f->max_iter && ((f->cy * f->cy + f->cx * f->cx) < 4.0))
	{
		temp = 2 * f->cx * f->cy + f->j_cy;
		f->cx = f->cx * f->cx - f->cy * f->cy + f->j_cx;
		f->cy = temp;
		n++;
	}
	mlx_put_pixel(f->img, f->x, f->y, ft_color(f));
	return (n);
}
