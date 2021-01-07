/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_objs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 22:10:00 by ybesbes           #+#    #+#             */
/*   Updated: 2021/01/07 22:10:05 by ybesbes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

void	fill_spheres(t_config_map *element, t_vars *vars)
{
	t_sphere	*sp;
	t_list		*new_sphere;

	sp = get_sphere_values(element, vars);
	if (sp != NULL)
	{
		new_sphere = ft_lstnew(sp);
		ft_lstadd_back(&vars->scene->spheres, new_sphere);
	}
}

void	fill_squares(t_config_map *element, t_vars *vars)
{
	t_square	*sq;
	t_list		*new_square;

	sq = get_square_values(element, vars);
	if (sq != NULL)
	{
		new_square = ft_lstnew(sq);
		ft_lstadd_back(&vars->scene->squares, new_square);
	}
}

void	fill_cylindres(t_config_map *element, t_vars *vars)
{
	t_cylindre	*cy;
	t_list		*new_cylindre;

	cy = get_cylindre_values(element, vars);
	if (cy != NULL)
	{
		new_cylindre = ft_lstnew(cy);
		ft_lstadd_back(&vars->scene->cylindres, new_cylindre);
	}
}

void	fill_planes(t_config_map *element, t_vars *vars)
{
	t_plane	*pl;
	t_list	*new_plane;

	pl = get_plane_values(element, vars);
	if (pl != NULL)
	{
		new_plane = ft_lstnew(pl);
		ft_lstadd_back(&vars->scene->planes, new_plane);
	}
}

void	fill_triangles(t_config_map *element, t_vars *vars)
{
	t_triangle	*tr;
	t_list		*new_triangle;

	tr = get_triangle_values(element, vars);
	if (tr != NULL)
	{
		new_triangle = ft_lstnew(tr);
		ft_lstadd_back(&vars->scene->triangles, new_triangle);
	}
}
