/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 22:21:30 by ybesbes           #+#    #+#             */
/*   Updated: 2021/01/07 22:21:32 by ybesbes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_H_
# define VEC_H_

# include "minirt.h"
# include <pthread.h>

# define PI 3.141592653589793
# define THREADS_NUM 8
# define INFO_HEADER_SIZE 54
# define MAX_VALUE 1E99
# define EPSILON 1e-6
# define SPHERE 0
# define SQUARE 1
# define PLANE 2
# define TRIANGLE 3
# define CYLINDRE 4
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126

typedef struct	s_equation
{
	double		a;
	double		b;
	double 		c;
	double		delta;
	double		t1;
	double		t2;
}				t_equation;

typedef struct	s_color
{
	double		r;
	double		g;
	double 		b;
}				t_color;

typedef struct	s_vector
{
	double	x;
	double	y;
	double	z;
}				t_vector;

typedef struct	s_ray
{
	t_vector	origine;
	t_vector	direction;
}				t_ray;

typedef struct	s_obj_info
{
	 t_vector	pos;
	 t_vector	norm;
	 int		type;
	 int		object_id;
	 double		t_min;
}				t_obj_info;

typedef struct	s_sphere
{
	double		rayon;
	t_vector	origine;
	t_color		color;
}				t_sphere;

typedef struct	s_plane
{
	t_vector	origine;
	t_vector	direction;
	t_color     color;
}				t_plane;

typedef struct	s_square
{
	double		hauteur;
	t_vector	origine;
	t_vector	direction;
	t_color		color;
}				t_square;

typedef struct	s_cylindre
{
	double		hauteur;
	double		diametre;
	t_vector	origine;
	t_vector	direction;
	t_color		color;
}				t_cylindre;

typedef struct	s_triangle
{
	t_vector	p1;
	t_vector	p2;
	t_vector	p3;
	t_color		color;
	t_vector	direction;
}				t_triangle;

typedef struct	s_lumiere
{
	double		intensite;
	double		ratio;
	t_color		color;
	t_vector	pos;
	t_vector	norm;
}				t_lumiere;

typedef struct	s_camera
{
	double		fov;
	t_vector	origine;
	t_vector	direction;
	t_vector	horizontal;
	t_vector	vertical;
	t_vector	lower_left_corner;
}				t_camera;

typedef struct	s_lum_ambiante
{
	double		ratio;
	t_color		couleur;
}				t_lum_ambiante;

typedef struct	s_scene
{
	t_resolution		resolution;
	t_lum_ambiante		lum_amb;
	t_list				*lumieres;
	t_list				*cameras;
	t_list				*spheres;
	t_list				*squares;
	t_list				*triangles;
	t_list				*planes;
	t_list				*cylindres;
	int					current_cam_id;
}				t_scene;


typedef struct	s_vars
{
	t_list	*lines;
	void	*mlx;
	void	*win;
	t_scene	*scene;
	t_data	*img;
	int		save;
	char	*error_msg;
}				t_vars;

typedef struct	s_args
{
	t_vars	*vars;
	int		thread_id;
}				t_args;

#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

#define min(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })

t_vector	ft_vec_add(t_vector v1, t_vector v2);
t_vector	ft_vec_sub(t_vector v1, t_vector v2);
t_vector	ft_vec_mult_v(t_vector v1, t_vector v2);
t_color		ft_col_mult_v(t_color c1, t_color c2);
t_vector	ft_vec_mult_d(double a, t_vector v);
t_color		ft_col_add(t_color c1, t_color c2);
t_color		ft_col_mult_d(double a, t_color c);
t_color		ft_col_div_d(double a, t_color c);
t_vector	ft_ver_sub_d(double a, t_vector v);
t_color		ft_col_clamp(t_color v);
double		ft_vec_dot(t_vector v1, t_vector v2);
double		ft_get_norm_carre(t_vector v);
void		ft_normalize(t_vector *v);
void			*print_scene(void *args);
t_vector 	ft_vec_norm(t_vector v);
t_vector	ft_vec_cross(t_vector v1, t_vector v2);
t_vector 	ft_vec_div_d(t_vector v, double d);
t_camera 	*get_camera_values(t_config_map *element, t_vars *vars);
t_lum_ambiante	get_lumiere_ambiante(t_config_map *element);
t_lumiere		*get_lumiere_values(t_config_map *element, t_vars *vars);
t_sphere	*get_sphere_values(t_config_map *element, t_vars *vars);
t_plane		*get_plane_values(t_config_map *element, t_vars *vars);
t_square	*get_square_values(t_config_map *element, t_vars *vars);
t_cylindre	*get_cylindre_values(t_config_map *element, t_vars *vars);
t_triangle	*get_triangle_values(t_config_map *element, t_vars *vars);
int 		ft_inter_all_spheres(t_scene *scene, t_ray *r, t_obj_info *obj_info);
int			ft_inter_all_planes(t_scene *scene, t_ray *r, t_obj_info *obj_info);
int			ft_inter_all_triangles(t_scene *scene, t_ray *r, t_obj_info *obj_info);
int			ft_inter_all_squares(t_scene *scene, t_ray *r, t_obj_info *obj_info);
int			ft_inter_all_cylinders(t_scene *scene, t_ray *r, t_obj_info *obj_info);
int			inter_plane(t_plane *pl, t_ray *r, double *t);
int			ft_inter_sphere(t_sphere *s , t_ray *r, double *t);
int			ft_solve_triangle_eq(t_vector u, t_vector v, t_vector w);
int			inter_triangle(t_triangle *tr, t_ray *r, double *t);
int			inter_square(t_square *sq, t_ray *r, double *t);
t_vector	get_cylinder_normal(t_cylindre *cylinder, double *t, t_ray *ray );
int			inter_cylinder_plane(t_cylindre *cy, double dist, double *t, t_ray *ray);
int			ft_solve_cylinder_eq(t_equation eq, t_cylindre *cy, t_ray *ray, double *t);
int			inter_cylinder(t_cylindre *cy, t_ray *ray,  double *t);
void		*get_from_list_by_id(t_list *list, int object_id);
int			ft_obj_info(int i, double t, t_obj_info *obj_info, t_ray *r);
int			ft_intersection(t_scene *scene , t_ray *r, t_obj_info *obj_info);
t_color		get_intersection_color(const t_obj_info *obj_info, t_scene *scene);
void		set_ambient_light(t_color *color, t_scene *scene);
void		get_intensite_pixel(t_scene *scene, t_lumiere *lum, t_obj_info obj_info, t_color *intensite_pixel);
t_color		get_color_obj_inter(t_ray *ray, t_scene *scene);
t_ray		compute_ray_direction(int line, int column, t_camera *cam, t_scene *scene);
int			create_trgb(t_color c, int endian);
int			press_key(int keycode,t_vars *vars);
void		ft_expose(void *param);
void 		init_current_cam(t_scene *scene);
int 		thread_init(t_vars *vars);
void		save_image(t_vars *vars);
void		extract_char_from_int(int filesize, unsigned char *str);
size_t		image_header(t_vars *vars, int fd, int filesize);
size_t		image_pixels(t_vars *vars, int fd, int pad);
t_vector	rotation(t_vector vec, t_vector angle);
size_t		ft_exit_failure(t_vars vars);
int			check_keys_and_values(t_vars *vars);
void		ft_free_scene(t_scene *scene);
int			check_values(t_config_map *element, t_vars *vars);
int			check_values_if_akey(t_config_map *element, t_vars *vars);
int			check_values_if_rkey(t_config_map *element, t_vars *vars);
int			check_values_if_ckey(t_config_map *element, t_vars *vars);
int			check_values_if_lkey(t_config_map *element, t_vars *vars);
int			check_values_if_sp_key(t_config_map *element, t_vars *vars);
int			check_values_if_plkey(t_config_map *element, t_vars *vars);
int			check_values_if_sq_key(t_config_map *element, t_vars *vars);
int			check_values_if_cy_key(t_config_map *element, t_vars *vars);
int			check_values_if_trkey(t_config_map *element, t_vars *vars);
int			ft_exit(t_vars *vars);
void		ft_free_map(t_list *list);
int			converting_ints_or_floats(char **tab, int *i, double min, double max);
void		fill_triangles(t_config_map *element, t_vars *vars);
void		fill_planes(t_config_map *element, t_vars *vars);
void		fill_cylindres(t_config_map *element, t_vars *vars);
void		fill_squares(t_config_map *element, t_vars *vars);
void		fill_spheres(t_config_map *element, t_vars *vars);
void		fill_scene(t_vars *vars);
void		read_config_file(char *config_file, t_vars *vars);
int			check_file_extention(char *filename);

#endif
