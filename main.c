/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:59:15 by candrese          #+#    #+#             */
/*   Updated: 2024/05/02 14:45:40 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_to_winit(t_fractol *f)
{
	f->x = 0;
	f->y = 0;
	f->y_max = 2.0;
	f->x_max = 1.5;
	f->y_min = -2.0;
	f->x_min = -2.5;
	f->zy = 0;
	f->zx = 0;
	f->cy = 0;
	f->cx = 0;
	f->max_iter = 100;
	f->iter = 0;
	f->color_scheme = 1;
	f->zoom = 1.4;
	f->mlx = mlx_init(WIDTH, HEIGHT, "fractol", false);
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->mlx || !f->img)
		exit(EXIT_FAILURE);
}

int	check_julia_values(char *s1, char *s2)
{
	while (*s1 != '\0')
	{
		if (*s1 == '-' || *s1 == '.' || (*s1 >= '0' && *s1 <= '9'))
			s1++;
		else
			return (1);
	}
	while (*s2 != '\0')
	{
		if (*s2 == '-' || *s2 == '.' || (*s2 >= '0' && *s2 <= '9'))
			s2++;
		else
			return (1);
	}
	return (0);
}

int	args(int ac, char **argv, t_fractol *f)
{
	if (ac == 2 && (!ft_strncmp("mandelbrot", argv[1], 11)
			|| !ft_strncmp("ship", argv[1], 4)))
		f->set = argv[1];
	else if (ac == 2 && !ft_strncmp("julia", argv[1], 6))
	{
		f->set = argv[1];
		f->j_cy = -0.59;
		f->j_cx = -0.4;
	}
	else if (ac == 4 && !ft_strncmp(argv[1], "julia", 6))
	{
		f->set = argv[1];
		if (check_julia_values(argv[2], argv[3]))
			return (1);
		f->j_cy = atod(argv[3]);
		f->j_cx = atod(argv[2]);
	}
	else
		return (1);
	return (0);
}

int	main(int ac, char **argv)
{
	t_fractol	f;

	if (args(ac, argv, &f))
	{
		putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	init_to_winit(&f);
	putstr_fd(MENU_MESSAGE, STDERR_FILENO);
	put_fractal(&f);
	mlx_key_hook(f.mlx, &input, &f);
	mlx_scroll_hook(f.mlx, &zoom, &f);
	mlx_loop(f.mlx);
	mlx_terminate(f.mlx);
	return (EXIT_SUCCESS);
}
