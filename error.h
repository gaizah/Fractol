/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeckers <ldeckers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 17:08:43 by ldeckers          #+#    #+#             */
/*   Updated: 2017/03/08 19:02:04 by ldeckers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
#define  ERROR_H

#include <unistd.h>
#include "fractol.h"

#define ARGUMENT_ERROR "Invalid argument\n"
#define	MALLOC_ERROR "Invalid malloc"

void 		ft_error(int e);

#endif
