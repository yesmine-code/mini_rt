/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 22:20:18 by ybesbes           #+#    #+#             */
/*   Updated: 2021/01/07 22:20:18 by ybesbes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

t_vector	ft_vec_add(t_vector v1, t_vector v2)
{
	t_vector	vfinal;

	vfinal.x = v1.x + v2.x;
	vfinal.y = v1.y + v2.y;
	vfinal.z = v1.z + v2.z;
	return (vfinal);
}

t_color		ft_col_add(t_color c1, t_color c2)
{
	t_color	cfinal;

	cfinal.r = c1.r + c2.r;
	cfinal.g = c1.g + c2.g;
	cfinal.b = c1.b + c2.b;
	return (cfinal);
}

t_vector	ft_vec_sub(t_vector v1, t_vector v2)
{
	t_vector	vfinal;

	vfinal.x = v1.x - v2.x;
	vfinal.y = v1.y - v2.y;
	vfinal.z = v1.z - v2.z;
	return (vfinal);
}

t_vector	ft_vec_mult_v(t_vector v1, t_vector v2)
{
	t_vector	vfinal;

	vfinal.x = v1.x * v2.x;
	vfinal.y = v1.y * v2.y;
	vfinal.z = v1.z * v2.z;
	return (vfinal);
}

t_color		ft_col_clamp(t_color v)
{
	t_color	vec;

	vec.r = max(min(v.r, 0.999), 0.);
	vec.g = max(min(v.g, 0.999), 0.);
	vec.b = max(min(v.b, 0.999), 0.);
	return (vec);
}
