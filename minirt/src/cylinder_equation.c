/*
 * cylinder_equation.c
 *
 *  Created on: 23 déc. 2020
 *      Author: user42
 */


#include "vec.h"

t_vector get_cylinder_normal(t_cylindre *cylinder, double *t, t_ray *ray )
{
	/*double tmp_t;
	t_plane	plan;
	t_ray r2;

	tmp_t = *t;
	plan.direction = cylinder->direction;
	plan.origine = cylinder->origine;
	r2.origine =  ray->origine;
	r2.direction = cylinder->direction;
	inter_plane(&plan, ray, &tmp_t);
	if (*t != tmp_t)
		return (ft_vec_norm(ft_vec_sub(ray->origine, ft_vec_add(cylinder->origine,
			ft_vec_mult_d(*t * -1, cylinder->direction)))));
	r2.origine =  ray->origine;
	r2.direction = ft_vec_mult_d(*t, cylinder->direction);
	inter_plane(&plan, &r2 , t);
	return (ft_vec_norm(ft_vec_sub(ray->origine, ft_vec_add(cylinder->origine,
				ft_vec_mult_d(*t, cylinder->direction)))));*/

	t_vector	norm;
	t_vector	axe;
	t_vector	v1n;

	t_vector p = ft_vec_add(ray->origine, ft_vec_mult_d(*t, ray->direction));
	norm = ft_vec_sub(p, cylinder->origine);
	v1n = ft_vec_norm(ft_vec_norm(cylinder->direction));
	axe = ft_vec_mult_d(fabs(ft_vec_dot(norm, v1n)), v1n);
	if (ft_vec_dot(norm, ft_vec_norm(cylinder->direction)) < 0)
		axe = ft_vec_mult_d(-1, axe);
	norm = ft_vec_sub(norm, axe);
	norm = ft_vec_norm(norm);

	return norm;
}

int inter_cylinder_plane(t_cylindre *cy, double dist, double *t, t_ray *ray)
{
	double plan_dist;
	t_plane plan;
	t_ray r;

	plan.origine = cy->origine;
	plan.direction = ft_vec_mult_d(-1 ,cy->direction);
	r.origine = ft_vec_add(ray->origine, ft_vec_mult_d(dist, ray->direction));
	r.direction = cy->direction;
	plan_dist = MAX_VALUE;
	if(inter_plane(&plan, &r, &plan_dist) && plan_dist < cy->hauteur)
	{
		*t = dist;
		return 1;
	}
	else
	{
		plan.direction = cy->direction;
		r.direction = ft_vec_mult_d(-1 ,cy->direction);
		if(inter_plane(&plan, &r, &plan_dist) && plan_dist < cy->hauteur)
		{
			*t = dist;
			return 1;
		}
	}
	return 0;
}

int ft_solve_cylinder_eq(t_equation eq, t_cylindre *cy, t_ray *ray, double *t)
{
	double dist;
	int ret;

	eq.delta = pow(eq.b, 2) - (4 * eq.a * eq.c);
	if (eq.delta < 0)
		return 0;
	eq.t1 = (-eq.b - sqrt(eq.delta)) / (2 * eq.a);
	eq.t2 = (-eq.b + sqrt(eq.delta)) / (2 * eq.a);
	dist = MAX_VALUE;
	if (eq.t1 >= 0)
		dist = eq.t1;
	else if (eq.t2 >= 0)
		dist = eq.t2;
	if (dist == MAX_VALUE)
		return 0;
	ret = inter_cylinder_plane(cy, dist, t, ray);
	if(ret == 0)
	{
		dist = eq.t1 + eq.t2 - dist;
		if(dist > 0)
			ret = inter_cylinder_plane(cy, dist, t, ray);
	}
	return ret;
}


int	inter_cylinder(t_cylindre *cy, t_ray *ray,  double *t)
{
	t_equation eq;
	t_vector cross1;
	t_vector cross2;

	cross1 = ft_vec_cross(ray->direction, cy->direction);
	cross2 = ft_vec_cross(ft_vec_sub(ray->origine, cy->origine), cy->direction);
	eq.a = ft_vec_dot(cross1, cross1);
	eq.b = 2 * ft_vec_dot(cross1, cross2);
	eq.c = ft_vec_dot(cross2, cross2) - (pow(cy->diametre / 2, 2)
		* ft_vec_dot(cy->direction, cy->direction));
	return(ft_solve_cylinder_eq(eq, cy, ray, t));
}
