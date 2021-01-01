/*
 * free_functions.c
 *
 *  Created on: 10 déc. 2020
 *      Author: user42
 */

#include "vec.h"

void	ft_free_tab(void **tab)
{
	int	i;

	i = 0;
	while(tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_free_list(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while(tmp != NULL)
	{
		free(tmp->content);
		tmp = tmp->next;
	}
	free(list);
}

void ft_free_scene(t_scene *scene)
{
	if(scene != NULL)
	{
		if(scene->cameras != NULL)
			ft_free_list(scene->cameras);
		if(scene->cylindres != NULL)
			ft_free_list(scene->cylindres);
		if(scene->lumieres != NULL)
			ft_free_list(scene->lumieres);
		if(scene->planes != NULL)
			ft_free_list(scene->planes);
		if(scene->spheres != NULL)
			ft_free_list(scene->spheres);
		if(scene->squares != NULL)
			ft_free_list(scene->squares);
		if(scene->triangles != NULL)
			ft_free_list(scene->triangles);;
		free(scene);
	}
}

size_t ft_exit_failure(t_vars vars)
{
	size_t size;

	size = write(1, "ERROR : ", 8);
	if(vars.error_msg != NULL)
	{
		size += write(1, vars.error_msg, ft_strlen(vars.error_msg));
		free(vars.error_msg);
	}
	if(vars.lines != NULL)
		ft_free_list(vars.lines);
	ft_free_scene(vars.scene);
	exit(EXIT_FAILURE);
	return(size);

}
