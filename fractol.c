/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeckers <ldeckers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 17:01:03 by ldeckers          #+#    #+#             */
/*   Updated: 2017/03/16 18:41:05 by ldeckers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	put_image(int x, int y, t_env *e, int color)
{

	char *pos;

	pos = e->mlx->data + y * e->mlx->sizeline + e->mlx->bpp / 8 * x;
	if (color == 0)
	{
		e->color.r = 0;
		e->color.g = 0;
		e->color.b = 0;
	}	
	else
	{
		e->color.r = (color & 0xFF0000) >> 16;
		e->color.g = (color & 0xFFFF) >> 8;
		e->color.b = (color & 0xFF);
	}
	*pos = e->color.b;
	*(pos + 1) = e->color.g;
	*(pos + 2) = e->color.r;
}

static void check_arg(t_env *e, char *av)
{
	if (!(ft_strcmp(av, "1")))
		e->f = mandelbrot;
	else if (!(ft_strcmp(av, "2")))
		e->f = julia;
	else if (!(ft_strcmp(av, "3")))
		e->f = uterus;
	else if (!(ft_strcmp(av, "4")))
		e->f = storm;
	else if (!(ft_strcmp(av, "5")))
		e->f = lustre;
	else if (!(ft_strcmp(av, "6")))
		e->f = ferie;
	else if (!(ft_strcmp(av, "7")))
		e->f = burning_ship;
	else
		ft_error(3);
}


void	*ft_aff(t_env *e, t_thread *t)
{
	t_env env[4];

	ft_dup_env(e, &(env[0]));
	ft_dup_env(e, &(env[1]));
	ft_dup_env(e, &(env[2]));
	ft_dup_env(e, &(env[3]));

	pthread_create(&t->th1, NULL, ft_first, &(env[0]));
	pthread_create(&t->th2, NULL, ft_scnd, &(env[1]));
	pthread_create(&t->th3, NULL, ft_three, &(env[2]));
	pthread_create(&t->th4, NULL, ft_four, &(env[3]));
	
	pthread_join(t->th1, NULL);
	pthread_join(t->th2, NULL);
	pthread_join(t->th3, NULL);
	pthread_join(t->th4, NULL);

	mlx_put_image_to_window(e->mlx->mlx, e->mlx->win, e->mlx->img, 0, 0);
	return (NULL);
}

int		red_cross(t_env *e)
{
	(void)e;
	exit(1);
	return (1);
}

int		main(int ac, char **av)
{
	t_env	e;
	t_thread t;

	if (ac != 2)
		ft_error(3);
	else
	 	check_arg(&e, av[1]);
	if (!(e.mlx = (t_mlx*)malloc(sizeof(t_mlx))))
		ft_error(2);
	ft_init_var(&e);
	ft_init_mlx(e.mlx);
	ft_aff(&e, &t);
	mlx_hook(e.mlx->win, 6, 1L << 6, mouse_hook, &e);
	mlx_mouse_hook(e.mlx->win, mouse_event, &e);
 	mlx_hook(e.mlx->win, 2, 0, ft_key_press, &e);
 	mlx_hook(e.mlx->win, 17, 0, red_cross, &e);
	mlx_loop(e.mlx->mlx);
	return (0);
}
