/*
 * vector2.c
 *
 *  Created on: 2 déc. 2020
 *      Author: user42
 */


#include "vec.h"

double ft_vec_dot(t_vector v1, t_vector v2)
{
	return(v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vector ft_vec_div_d(t_vector v, double d)
{
	t_vector v1;
	v1.x = v.x / d;
	v1.y = v.y / d;
	v1.z = v.z / d;
	return (v1);
}

double ft_get_norm_carre(t_vector v)
{
	return(v.x * v.x + v.y * v.y + v.z *v.z);
}

t_vector ft_vec_norm(t_vector v)
{
	t_vector result;
	double norm;
	norm = sqrt(ft_get_norm_carre(v));
	result.x = v.x / norm;
	result.y = v.y / norm;
	result.z = v.z / norm;
	return (result);

}

t_vector	ft_vec_cross(t_vector v1, t_vector v2)
{
	t_vector	v;

	v.x = v1.y * v2.z - v1.z * v2.y;
	v.y = v1.z * v2.x - v1.x * v2.z;
	v.z = v1.x * v2.y - v1.y * v2.x;
	return (v);
}
