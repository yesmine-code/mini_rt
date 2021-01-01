/*
 * inter_all_obj.c
 *
 *  Created on: 23 déc. 2020
 *      Author: user42
 */

#include "vec.h"

int ft_inter_all_spheres(t_scene *scene, t_ray *r, t_obj_info *obj_info)
{
	int i;
	int has_inter;
	double t;
	t_list *spheres;

	spheres = scene->spheres;
	i = 0;
	has_inter = 0;
	while(spheres)
	{
		t_sphere *sp;
		sp = spheres->content;
		if (ft_inter_sphere(sp, r, &t) == 1 && t < obj_info->t_min)
		{
			obj_info->type = SPHERE;
			has_inter = ft_obj_info(i, t, obj_info, r);
			obj_info->norm = ft_vec_norm(ft_vec_sub(obj_info->pos,sp->origine));
		}
		spheres = spheres->next;
		i++;
	}
	return has_inter;
}

int ft_inter_all_planes(t_scene *scene, t_ray *r, t_obj_info *obj_info)
{
	int i;
	int has_inter;
	double t;
	t_list *planes;
	t_plane *pl;

	has_inter = 0;
	i = 0;
	planes = scene->planes;
	while(planes)
	{
		pl = planes->content;
		if(inter_plane(pl, r, &t) && t < obj_info->t_min)
		{
			obj_info->type = PLANE;
			has_inter = ft_obj_info(i, t, obj_info, r);
			obj_info->norm = ft_vec_norm(pl->direction);
		}
		planes = planes->next;
		i++;
	}
	return has_inter;
}

int ft_inter_all_triangles(t_scene *scene, t_ray *r, t_obj_info *obj_info)
{
	int i;
	int has_inter;
	t_list *triangles;
	double t;

	triangles = scene->triangles;
	i = 0;
	has_inter = 0;
	t = 0;
	while(triangles)
	{
		t_triangle *tr;
		tr = triangles->content;
		if(inter_triangle(tr, r, &t) && t < obj_info->t_min)
		{
			obj_info->type = TRIANGLE;
			has_inter = ft_obj_info(i, t, obj_info, r);
			obj_info->norm = ft_vec_norm(tr->direction);
		}
		triangles = triangles->next;
		i++;
	}
	return has_inter;
}

int ft_inter_all_squares(t_scene *scene, t_ray *r, t_obj_info *obj_info)
{
	int i;
	int has_inter;
	double t;
	t_list	*squares;

	squares = scene->squares;
	i = 0;
	has_inter = 0;
	t = 0;
	while(squares)
	{
		t_square *sq;
		sq = squares->content;
		if(inter_square(sq, r, &t) && t < obj_info->t_min)
		{
			obj_info->type = SQUARE;
			has_inter = ft_obj_info(i, t, obj_info, r);
			obj_info->norm = ft_vec_norm(sq->direction);
		}
		squares = squares->next;
		i++;
	}
	return has_inter;
}

int ft_inter_all_cylinders(t_scene *scene, t_ray *r, t_obj_info *obj_info)
{
	int i;
	int has_inter;
	double t;

	i = 0;
	has_inter = 0;
	t = 0;
	t_list *cylindres;
	cylindres = scene->cylindres;
	i = 0;
	while(cylindres)
	{
		t_cylindre *cy;
		cy = cylindres->content;
		if(inter_cylinder(cy, r, &t) == 1 && t < obj_info->t_min)
		{
			obj_info->type = CYLINDRE;
			has_inter = ft_obj_info(i, t, obj_info, r);
			obj_info->norm = get_cylinder_normal(cy, &t, r);
		}
		cylindres = cylindres->next;
		i++;
	}
	return has_inter;
}
