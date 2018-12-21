/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeckers <ldeckers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 11:24:10 by ldeckers          #+#    #+#             */
/*   Updated: 2017/01/26 14:47:11 by ldeckers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_init_mlx(t_mlx *mlx)
{
	if (!(mlx->mlx = mlx_init()))
		return (0);
	else if (!(mlx->win = mlx_new_window(mlx->mlx, mlx->width,
		mlx->height, mlx->name)))
		return (0);
	else if (!(mlx->img = mlx_new_image(mlx->mlx, mlx->width, mlx->height)))
		return (0);
	else if (!(mlx->data = mlx_get_data_addr(mlx->img,
		&(mlx->bpp), &(mlx->sizeline), &(mlx->endian))))
		return (0);
	return (1);
}
