/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeckers <ldeckers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 17:04:22 by ldeckers          #+#    #+#             */
/*   Updated: 2017/03/16 18:41:24 by ldeckers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define  FRACTOL_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include "error.h"
# include <stdlib.h>
# include <math.h>
# include <pthread.h>

typedef struct 	s_thread
{
	pthread_t	th1;
	pthread_t	th2;
	pthread_t	th3;
	pthread_t	th4;

}				t_thread;

typedef struct 		s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

typedef struct		s_var
{
	double				zoom;
}					t_var;

typedef	struct		s_env
{
	t_mlx			*mlx;
	t_var			a;
	t_color			color;
	int				it_max;
	int 			i;
	int 			old_r;
	int 			old_i;
	int 			mouse;
	double			x1;
	// double			x2;
	double			y1;
	// double			y2;
	double			tmp_r;
	double			tmp_i;
	double			c_r;
	double			c_i;
	double			zoomx;
	double			zoomy;
	void			(*f)(double, double, struct s_env *);

	double			step_x;
	double			step_y;
	double			center_x;
	double			center_y;
}					t_env;

void	*ft_aff(t_env *e, t_thread *t);
void	ft_init_var(t_env *e);
void	put_image(int x, int y, t_env *e, int color);
int		ft_key_press(int keycode, t_env *e);

void 	mandelbrot(double i, double j, t_env *e);
void	julia(double r, double i, t_env *e);
void	storm(double r, double i, t_env *e);
void	uterus(double r, double i, t_env *e);
void	lustre(double r, double i, t_env *e);
void	ferie(double r, double i, t_env *e);
void	burning_ship(double r, double i, t_env *e);
void	buddhabrot(double r, double i, t_env *e);
void	ft_zoom(int keycode, t_env *e);
void	ft_dup_env(t_env *e, t_env *env);
void	*ft_first(void *env);
void	*ft_scnd(void *env);
void	*ft_three(void *env);
void	*ft_four(void *env);
int		mouse_event(int keycode, int x, int y, t_env *e);
// int		ft_key_mouse(int key, int x, int y, t_env *e);
int 	mouse_hook(int x, int y, t_env *e);

#endif
