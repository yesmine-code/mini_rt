/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 22:16:49 by ybesbes           #+#    #+#             */
/*   Updated: 2021/01/13 22:15:48 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

int	ft_exit(t_vars *vars)
{
	ft_free_map(vars->lines);
	ft_free_scene(vars->scene);
	if (vars->save == 0)
		mlx_destroy_window(vars->mlx, vars->win);
	exit(EXIT_SUCCESS);
	return (0);
}

int	press_key_cam_mov(int keycode, t_camera *cam)
{
	if (keycode == 65362 || keycode == KEY_UP)
		cam->origine = ft_vec_add(cam->origine,
		ft_vec_mult_d(-0.08, ft_vec_cross(cam->vertical, cam->horizontal)));
	else if (keycode == 65364 || keycode == KEY_DOWN)
		cam->origine = ft_vec_add(cam->origine,
		ft_vec_mult_d(0.08, ft_vec_cross(cam->vertical, cam->horizontal)));
	else if (keycode == 65361 || keycode == KEY_LEFT)
		cam->origine = ft_vec_add(cam->origine,
		ft_vec_mult_d(-0.08, cam->horizontal));
	else if (keycode == 65363 || keycode == KEY_RIGHT)
		cam->origine = ft_vec_add(cam->origine,
		ft_vec_mult_d(0.08, cam->horizontal));
	else if (keycode == 'r')
		cam->direction = rotation(cam->direction, (t_vector){0, -1, 0});
	else if (keycode == 't')
		cam->direction = rotation(cam->direction, (t_vector){0, 1, 0});
	else
		return (0);
	return (1);
}

int	press_key(int keycode, t_vars *vars)
{
	t_camera *cam;

	cam = get_from_list_by_id(vars->scene->cameras,
		vars->scene->current_cam_id);
	if (keycode == 'c')
		vars->scene->current_cam_id = (vars->scene->current_cam_id + 1)
		% ft_lstsize(vars->scene->cameras);
	else if (keycode == 'x')
		vars->scene->current_cam_id = (vars->scene->current_cam_id
		+ ft_lstsize(vars->scene->cameras) - 1) %
		ft_lstsize(vars->scene->cameras);
	else if (keycode == 65307 || keycode == 27)
		ft_exit(vars);
	else if (press_key_cam_mov(keycode, cam) == 0)
		return (0);
	else
		return (0);
	mlx_loop_hook(vars->mlx, &thread_init, vars);
	return (1);
}
