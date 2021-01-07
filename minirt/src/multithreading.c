/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multithreading.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 22:18:17 by ybesbes           #+#    #+#             */
/*   Updated: 2021/01/07 22:18:19 by ybesbes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

int	thread_creation(t_vars *vars, pthread_t *p)
{
	t_args		args[THREADS_NUM];
	int			i;

	i = 0;
	init_current_cam(vars->scene);
	while (i < THREADS_NUM)
	{
		args[i].thread_id = i;
		args[i].vars = vars;
		pthread_create(&p[i], NULL, &print_scene, &args[i]);
		i++;
	}
	return (i);
}

int	thread_init(t_vars *vars)
{
	int			i;
	pthread_t	p[THREADS_NUM];

	i = thread_creation(vars, p);
	while (i > 0)
		pthread_join(p[--i], NULL);
	if (vars->save == 1)
		save_image(vars);
	else
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	return (0);
}
