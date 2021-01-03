/*
 * get_structs2.c
 *
 *  Created on: 10 déc. 2020
 *      Author: user42
 */


#include "vec.h"

t_sphere	*get_sphere_values(t_config_map *element, t_vars *vars)
{
	char	**tab;
	t_sphere *sp = NULL;

	sp = malloc(sizeof(t_sphere));
	if(sp == NULL)
	{
		vars->error_msg = ft_strdup("technical error");
		ft_exit_failure(*vars);
	}
	tab = ft_split(element->value[0], ',');
	convert_char_to_float(tab[0], &(sp->origine.x));
	convert_char_to_float(tab[1], &(sp->origine.y));
	convert_char_to_float(tab[2], &(sp->origine.z));
	ft_free_tab((void**)tab, 1);
	convert_char_to_float(element->value[1], &sp->rayon);
	sp->rayon = sp->rayon / 2;
	tab = ft_split(element->value[2], ',');
	sp->color.r = ft_atoi(tab[0]);
	sp->color.g = ft_atoi(tab[1]);
	sp->color.b = ft_atoi(tab[2]);
	ft_free_tab((void**)tab, 1);
	return (sp);
}

t_plane	*get_plane_values(t_config_map *element, t_vars *vars)
{
	char	**tab;
	t_plane *pl = NULL;

	pl = malloc(sizeof(t_plane));
	if(pl == NULL)
	{
		vars->error_msg = ft_strdup("technical error");
		ft_exit_failure(*vars);
	}
	tab = ft_split(element->value[0], ',');
	convert_char_to_float(tab[0], &(pl->origine.x));
	convert_char_to_float(tab[1], &(pl->origine.y));
	convert_char_to_float(tab[2], &(pl->origine.z));
	ft_free_tab((void**)tab, 1);
	tab = ft_split(element->value[1], ',');
	convert_char_to_float(tab[0], &(pl->direction.x));
	convert_char_to_float(tab[1], &(pl->direction.y));
	convert_char_to_float(tab[2], &(pl->direction.z));
	ft_free_tab((void**)tab, 1);
	tab = ft_split(element->value[2], ',');
	pl->color.r = ft_atoi(tab[0]);
	pl->color.g = ft_atoi(tab[1]);
	pl->color.b = ft_atoi(tab[2]);
	ft_free_tab((void**)tab, 1);
	return (pl);
}

t_square	*get_square_values(t_config_map *element, t_vars *vars)
{
	char	**tab;
	t_square	*sq = NULL;

	sq = malloc(sizeof(t_square));
	if(sq == NULL)
	{
			vars->error_msg = ft_strdup("technical error");
			ft_exit_failure(*vars);
	}
	tab = ft_split(element->value[0], ',');
	convert_char_to_float(tab[0], &(sq->origine.x));
	convert_char_to_float(tab[1], &(sq->origine.y));
	convert_char_to_float(tab[2], &(sq->origine.z));
	ft_free_tab((void**)tab, 1);
	tab = ft_split(element->value[1], ',');
	convert_char_to_float(tab[0], &(sq->direction.x));
	convert_char_to_float(tab[1], &(sq->direction.y));
	convert_char_to_float(tab[2], &(sq->direction.z));
	ft_free_tab((void**)tab, 1);
	convert_char_to_float(element->value[2], &sq->hauteur);
	tab = ft_split(element->value[3], ',');
	sq->color.r = ft_atoi(tab[0]);
	sq->color.g = ft_atoi(tab[1]);
	sq->color.b = ft_atoi(tab[2]);
	ft_free_tab((void**)tab, 1);
	return (sq);
}

t_cylindre	*get_cylindre_values(t_config_map *element, t_vars *vars)
{
	char	**tab;
	t_cylindre *cy = NULL;

	cy = malloc(sizeof(t_cylindre));
	if(cy == NULL)
	{
		vars->error_msg = ft_strdup("technical error");
		ft_exit_failure(*vars);
	}
	tab = ft_split(element->value[0], ',');
	convert_char_to_float(tab[0], &(cy->origine.x));
	convert_char_to_float(tab[1], &(cy->origine.y));
	convert_char_to_float(tab[2], &(cy->origine.z));
	ft_free_tab((void**)tab, 1);
	tab = ft_split(element->value[1], ',');
	convert_char_to_float(tab[0], &(cy->direction.x));
	convert_char_to_float(tab[1], &(cy->direction.y));
	convert_char_to_float(tab[2], &(cy->direction.z));
	ft_free_tab((void**)tab, 1);
	convert_char_to_float(element->value[2], &cy->diametre);
	convert_char_to_float(element->value[3], &cy->hauteur);
	tab = ft_split(element->value[4], ',');
	cy->color.r = ft_atoi(tab[0]);
	cy->color.g = ft_atoi(tab[1]);
	cy->color.b = ft_atoi(tab[2]);
	ft_free_tab((void**)tab, 1);
	return (cy);
}

t_triangle	*get_triangle_values(t_config_map *element, t_vars *vars)
{
	char	**tab;
	t_triangle *tr = NULL;

	tr = malloc(sizeof(t_triangle));
	if(tr == NULL)
	{
		vars->error_msg = ft_strdup("technical error");
		ft_exit_failure(*vars);
	}
	tab = ft_split(element->value[0], ',');
	convert_char_to_float(tab[0], &(tr->p1.x));
	convert_char_to_float(tab[1], &(tr->p1.y));
	convert_char_to_float(tab[2], &(tr->p1.z));
	ft_free_tab((void**)tab, 1);
	tab = ft_split(element->value[1], ',');
	convert_char_to_float(tab[0], &(tr->p2.x));
	convert_char_to_float(tab[1], &(tr->p2.y));
	convert_char_to_float(tab[2], &(tr->p2.z));
	ft_free_tab((void**)tab, 1);
	tab = ft_split(element->value[2], ',');
	convert_char_to_float(tab[0], &(tr->p3.x));
	convert_char_to_float(tab[1], &(tr->p3.y));
	convert_char_to_float(tab[2], &(tr->p3.z));
	ft_free_tab((void**)tab, 1);
	tab = ft_split(element->value[3], ',');
	tr->color.r = ft_atoi(tab[0]);
	tr->color.g = ft_atoi(tab[1]);
	tr->color.b = ft_atoi(tab[2]);
	tr->direction = ft_vec_cross(ft_vec_sub(tr->p2, tr->p1),
				ft_vec_sub(tr->p3, tr->p1));
	ft_free_tab((void**)tab, 1);
	return (tr);
}
