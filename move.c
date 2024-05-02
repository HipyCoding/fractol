/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 10:00:11 by candrese          #+#    #+#             */
/*   Updated: 2024/04/30 19:20:57 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move_up(t_fractol *f)
{
	double	middle;

	middle = f->x_max - f->x_min;
	f->y_min -= middle * 0.1;
	f->y_max -= middle * 0.1;
}

void	move_down(t_fractol *f)
{
	double	middle;

	middle = f->x_max - f->x_min;
	f->y_min += middle * 0.1;
	f->y_max += middle * 0.1;
}

void	move_left(t_fractol *f)
{
	double	middle;

	middle = f->x_max - f->x_min;
	f->x_min -= middle * 0.1;
	f->x_max -= middle * 0.1;
}

void	move_right(t_fractol *f)
{
	double	middle;

	middle = f->x_max - f->x_min;
	f->x_min += middle * 0.1;
	f->x_max += middle * 0.1;
}
