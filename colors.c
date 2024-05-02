/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 04:00:03 by candrese          #+#    #+#             */
/*   Updated: 2024/04/30 17:41:05 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	ft_color(t_fractol *f)
{
	if (f->iter == f->max_iter)
		return (ft_pixel (0, 0, 0, 255));
	else if (f->iter < f->max_iter && f->color_scheme == 1)
	{
		f->r = (int)(sin(0.1 * f->iter) * 127 + 128);
		f->g = (int)(sin(0.2 * f->iter) * 127 + 128);
		f->b = (int)(sin(0.3 * f->iter) * 127 + 128);
	}
	else if (f->iter < f->max_iter && f->color_scheme == 2)
	{
		f->r = (int)(200 + 55 * sin(0.1 * f->iter));
		f->g = (int)(100 + 55 * sin(0.2 * f->iter));
		f->b = (int)(50 + 55 * sin(0.3 * f->iter));
	}
	else if (f->iter < f->max_iter && f->color_scheme == 3)
	{
		f->r = (int)(sin(0.1 * f->iter + 0) * 127 + 128);
		f->g = (int)(sin(0.1 * f->iter + 2) * 127 + 128);
		f->b = (int)(sin(0.1 * f->iter + 4) * 127 + 128);
	}
	return (ft_pixel (f->r, f->g, f->b, 255));
}
