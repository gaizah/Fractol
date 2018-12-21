/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keypress.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeckers <ldeckers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 17:52:26 by ldeckers          #+#    #+#             */
/*   Updated: 2017/03/16 18:17:07 by ldeckers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	ft_moove(int keycode, t_env *e)
{
	if (keycode == 123)
		e->x1 /= 1.1;
	else if (keycode == 124)
		e->x1 *= 1.1;
	else if (keycode == 125)
		e->y1 *= 1.1;
	else if (keycode == 126)
		e->y1 /= 1.1;
}

int		mouse_event(int keycode, int x, int y, t_env *e)
{
	t_thread t;

	(void)x;
	(void)y;

	if (keycode == 6)
	{
		e->x1 *= 1.1;
		e->y1 *= 1.1;
		e->center_x *= 1.1;
		e->center_y *= 1.1;
	}
	else if (keycode == 7)
	{
		e->x1 /= 1.1;
		e->y1 /= 1.1;
		e->center_x /= 1.1;
		e->center_y /= 1.1;
	}
	ft_aff(e, &t);
	return (0);
}

int 	mouse_hook(int r, int i, t_env *e)
{
	t_thread t;

	if (!(r > e->mlx->width || i > e->mlx->height || r < 0 || i < 0 || e->mouse == -1))
	{
		if (e->old_r != r)
			e->c_r += (r - e->old_r) / (e->mlx->height * e->zoomx * 100);
		if (e->old_i != i)
			e->c_i += (i - e->old_i) / (e->mlx->width * e->zoomy * 100);
	}
	ft_aff(e, &t);
	e->old_r = r;
	e->old_i = i;
	return (0);
}

int		ft_key_press(int keycode, t_env *e)
{
	t_thread t;
	if (e->mlx->img)
	{
		mlx_destroy_image(e->mlx->mlx, e->mlx->img);
		e->mlx->img = mlx_new_image(e->mlx->mlx, e->mlx->width, e->mlx->height);
		e->mlx->data = mlx_get_data_addr(e->mlx->img, &e->mlx->bpp, &e->mlx->sizeline, &e->mlx->endian);
	}
	if (keycode == 46)
		e->mouse *= -1;
	else if (keycode == 53)
		exit(1);
	else if (keycode >= 123 && keycode <= 126)
		ft_moove(keycode, e);
	else if (keycode == 69)
			e->it_max++;
	else if (keycode == 78)
			e->it_max--;
	ft_aff(e, &t);
	return (0);
}

void 	ft_init_var(t_env *e)
{
	e->step_x = 0;
	e->step_y = 0;
	e->mlx->width = 800;
	e->mlx->height = 600;
	e->x1 = -2;
	e->y1 = -2;
	e->tmp_r = 0;
	e->tmp_i = 0;
	e->c_r = 0;
	e->c_i = 0;
	e->old_r = -1;
	e->old_i = -1;
	e->it_max = 200;
	e->mouse = -1;
	e->center_x = 4;
	e->center_y = 4;
	e->zoomx = e->center_x / e->mlx->width;
	e->zoomy = e->center_y / e->mlx->height;
	e->mlx->name = "fractol";
}
