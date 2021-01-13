/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 22:08:28 by ybesbes           #+#    #+#             */
/*   Updated: 2021/01/07 22:08:31 by ybesbes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

int	create_trgb(t_color c, int endian)
{
	int t;

	t = 0;
	if (endian == 0)
		return (t << 24 | (int)c.r << 16 | (int)c.g << 8 | (int)c.b);
	return ((int)c.b << 24 | (int)c.g << 16 | (int)c.r << 8 | t);
}
