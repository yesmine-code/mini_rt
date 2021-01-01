/*
 * obj_equation.c
 *
 *  Created on: 23 déc. 2020
 *      Author: user42
 */


#include "vec.h"

int inter_plane(t_plane *pl, t_ray *r, double *t)
{
	double denom;
	double numer;

	denom = ft_vec_dot(r->direction, pl->direction);
	numer = ft_vec_dot(ft_vec_sub(r->origine, pl->origine), pl->direction);
	if(denom <= EPSILON)
	{
		*t = -numer / denom;
		if (*t >= 0)
			return 1;
	}
	return(0);
}

int	ft_inter_sphere(t_sphere *s , t_ray *r, double *t)
{
	t_equation eq;

	eq.a = ft_vec_dot(r->direction, r->direction);
	eq.b = 2 * ft_vec_dot(r->direction, ft_vec_sub(r->origine, s->origine));
	eq.c = ft_get_norm_carre(ft_vec_sub(r->origine, s->origine)) - (s->rayon * s->rayon);
	eq.delta = eq.b * eq.b - 4 * eq.a * eq.c;
	if (eq.delta < 0)
		return 0;
	eq.t1 = (-eq.b - sqrt(eq.delta)) / (2 * eq.a);
	eq.t2 = (-eq.b + sqrt(eq.delta)) / (2 * eq.a);
	if (eq.t2 < 0)
		return 0;
	*t = eq.t1 > 0 ? eq.t1 : eq.t2;
	return 1;
}

int ft_solve_triangle_eq(t_vector u, t_vector v, t_vector w)
{
	double detm;
	double detb;
	double detg;
	t_equation eq;

	detm = ft_get_norm_carre(u) * ft_get_norm_carre(v) - ft_vec_dot(u, v) * ft_vec_dot(u, v);
	detb = ft_vec_dot(w, u) * ft_get_norm_carre(v) - ft_vec_dot(w, v) * ft_vec_dot(u, v);
	eq.b = detb / detm;
	detg = ft_get_norm_carre(u) * ft_vec_dot(w, v) - ft_vec_dot(u, v) * ft_vec_dot(w, u);
	eq.c = detg / detm;
	eq.a = 1 - eq.b - eq.c;
	if (eq.a < 0 || eq.c < 0 || eq.b < 0 || eq.a > 1 || eq.c > 1 || eq.b > 1)
		return 0;
	return 1;
}

int inter_triangle(t_triangle *tr, t_ray *r, double *t)
{
	t_vector P;
	t_vector u;
	t_vector v;
	t_vector w;

	*t = ft_vec_dot(ft_vec_sub(tr->p3, r->origine), ft_vec_norm(tr->direction)) /
			ft_vec_dot(r->direction, ft_vec_norm(tr->direction));
	P = ft_vec_add(r->origine, ft_vec_mult_d(*t, r->direction));
	if(*t < 0)
		return 0;
	u = ft_vec_sub(tr->p2, tr->p1);
	v = ft_vec_sub(tr->p3, tr->p1);
	w = ft_vec_sub(P, tr->p1);
	return ft_solve_triangle_eq(u, v, w);
}

int	inter_square(t_square *sq, t_ray *r, double *t)
{
	t_equation eq;
	t_vector d;

	eq.a = ft_vec_dot(r->direction, sq->direction);
	eq.b = ft_vec_dot(ft_vec_sub(r->origine, sq->origine), sq->direction);
	if(!(eq.a == 0 || (eq.b < 0 && eq.a < 0) || (eq.b > 0 && eq.a > 0)))
	{
		eq.t1 = -eq.b / eq.a;
		if(eq.t1 > 0)
		{
			eq.t2 = sq->hauteur / 2;
			d = ft_vec_sub(ft_vec_add(ft_vec_mult_d(eq.t1, r->direction), r->origine), sq->origine);
			if (!(fabs(d.x) > eq.t2 || fabs(d.y) > eq.t2 || fabs(d.z) > eq.t2))
			{
				*t = eq.t1;
				return 1;
			}
		}
	}
	return(0);
}
