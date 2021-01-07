/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_structs2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 22:15:54 by ybesbes           #+#    #+#             */
/*   Updated: 2021/01/07 22:15:56 by ybesbes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

t_sphere	*get_sphere_values(t_config_map *element, t_vars *vars)
{
	char		**tab;
	t_sphere	*sp;

	sp = NULL;
	sp = malloc(sizeof(t_sphere));
	if (sp == NULL)
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

void		get_plane_floats(t_plane *pl, t_config_map *element)
{
	char	**tab;

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
}

t_plane		*get_plane_values(t_config_map *element, t_vars *vars)
{
	char	**tab;
	t_plane	*pl;

	pl = NULL;
	pl = malloc(sizeof(t_plane));
	if (pl == NULL)
	{
		vars->error_msg = ft_strdup("technical error");
		ft_exit_failure(*vars);
	}
	get_plane_floats(pl, element);
	tab = ft_split(element->value[2], ',');
	pl->color.r = ft_atoi(tab[0]);
	pl->color.g = ft_atoi(tab[1]);
	pl->color.b = ft_atoi(tab[2]);
	ft_free_tab((void**)tab, 1);
	return (pl);
}

void		get_square_floats(t_square *sq, t_config_map *element)
{
	char	**tab;

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
}

t_square	*get_square_values(t_config_map *element, t_vars *vars)
{
	char		**tab;
	t_square	*sq;

	sq = NULL;
	sq = malloc(sizeof(t_square));
	if (sq == NULL)
	{
		vars->error_msg = ft_strdup("technical error");
		ft_exit_failure(*vars);
	}
	get_square_floats(sq, element);
	convert_char_to_float(element->value[2], &sq->hauteur);
	tab = ft_split(element->value[3], ',');
	sq->color.r = ft_atoi(tab[0]);
	sq->color.g = ft_atoi(tab[1]);
	sq->color.b = ft_atoi(tab[2]);
	ft_free_tab((void**)tab, 1);
	return (sq);
}
