/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 22:20:01 by ybesbes           #+#    #+#             */
/*   Updated: 2021/01/07 22:20:02 by ybesbes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

t_color		ft_col_mult_v(t_color c1, t_color c2)
{
	t_color	cfinal;

	cfinal.r = c1.r * c2.r;
	cfinal.g = c1.g * c2.g;
	cfinal.b = c1.b * c2.b;
	return (cfinal);
}

t_vector	ft_vec_mult_d(double a, t_vector v)
{
	t_vector	vfinal;

	vfinal.x = v.x * a;
	vfinal.y = v.y * a;
	vfinal.z = v.z * a;
	return (vfinal);
}

t_color		ft_col_mult_d(double a, t_color c)
{
	t_color	cfinal;

	cfinal.r = c.r * a;
	cfinal.g = c.g * a;
	cfinal.b = c.b * a;
	return (cfinal);
}

t_color		ft_col_div_d(double a, t_color c)
{
	t_color	cfinal;

	cfinal.r = c.r / a;
	cfinal.g = c.g / a;
	cfinal.b = c.b / a;
	return (cfinal);
}

t_vector	ft_ver_sub_d(double a, t_vector v)
{
	t_vector	vfinal;

	vfinal.x = v.x / a;
	vfinal.y = v.y / a;
	vfinal.z = v.z / a;
	return (vfinal);
}
