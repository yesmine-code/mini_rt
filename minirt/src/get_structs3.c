/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_structs3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 22:16:14 by ybesbes           #+#    #+#             */
/*   Updated: 2021/01/07 22:16:15 by ybesbes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

void		get_cylinder_floats(t_cylindre *cy, t_config_map *element)
{
	char	**tab;

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
}

t_cylindre	*get_cylindre_values(t_config_map *element, t_vars *vars)
{
	char		**tab;
	t_cylindre	*cy;

	cy = NULL;
	cy = malloc(sizeof(t_cylindre));
	if (cy == NULL)
	{
		vars->error_msg = ft_strdup("technical error");
		ft_exit_failure(*vars);
	}
	get_cylinder_floats(cy, element);
	convert_char_to_float(element->value[2], &cy->diametre);
	convert_char_to_float(element->value[3], &cy->hauteur);
	tab = ft_split(element->value[4], ',');
	cy->color.r = ft_atoi(tab[0]);
	cy->color.g = ft_atoi(tab[1]);
	cy->color.b = ft_atoi(tab[2]);
	ft_free_tab((void**)tab, 1);
	return (cy);
}

void		get_triangle_points(t_triangle *tr, t_config_map *element)
{
	char	**tab;

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
}

t_triangle	*get_triangle_values(t_config_map *element, t_vars *vars)
{
	char		**tab;
	t_triangle	*tr;

	tr = NULL;
	tr = malloc(sizeof(t_triangle));
	if (tr == NULL)
	{
		vars->error_msg = ft_strdup("technical error");
		ft_exit_failure(*vars);
	}
	get_triangle_points(tr, element);
	tab = ft_split(element->value[3], ',');
	tr->color.r = ft_atoi(tab[0]);
	tr->color.g = ft_atoi(tab[1]);
	tr->color.b = ft_atoi(tab[2]);
	tr->direction = ft_vec_cross(ft_vec_sub(tr->p2, tr->p1),
				ft_vec_sub(tr->p3, tr->p1));
	ft_free_tab((void**)tab, 1);
	return (tr);
}
