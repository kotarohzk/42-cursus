/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:06:32 by jseo              #+#    #+#             */
/*   Updated: 2021/04/17 16:19:34 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

/*
** =============================================================================
** Dependencies
** =============================================================================
*/

# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdint.h>
# include <pthread.h>

/*
** =============================================================================
** Result Macros
** =============================================================================
*/

# define TRUE 			1
# define FALSE 			0
# define VALID			0
# define INVALID		1
# define CHECK			1
# define PARSE			0
# define SUCCESS		1
# define END			0
# define ERROR 			-1

/*
** =============================================================================
** Type Macros
** =============================================================================
*/

# define FRONT			1
# define BACK			0
# define LAMBERTIAN		0
# define METAL			1
# define DIELECTRIC		2
# define FILTER_NOTHING	0
# define FILTER_SEPIA	1
# define FILTER_RED		2
# define FILTER_GREEN	3
# define FILTER_BLUE	4

/*
** =============================================================================
** Hidden Mode Sphere Macros
** =============================================================================
*/

# define SP_NOTHING		0
# define SP_NORMAL		1
# define SP_CHECKER		2
# define SP_RANDOM		3

/*
** =============================================================================
** Identifier Macros
** =============================================================================
*/

# define NOTHING		0
# define RESOLUTION		1
# define AMBIENT		2
# define CAMERA			3
# define LIGHT			4
# define SPHERE			5
# define PLANE			6
# define SQUARE			7
# define CYLINDER		8
# define TRIANGLE		9

/*
** =============================================================================
** Key Macros
** =============================================================================
*/

# define KEY_TERM		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_Q			12
# define KEY_E			14
# define KEY_UP			126
# define KEY_LEFT		123
# define KEY_DOWN		125
# define KEY_RIGHT		124
# define KEY_CMA		43
# define KEY_SLH		44
# define KEY_N			45
# define KEY_M			46
# define KEY_1			18
# define KEY_2			19
# define KEY_3			20
# define KEY_4			21
# define KEY_I			34
# define KEY_P			35
# define KEY_K			40
# define KEY_SEMI		41
# define KEY_Z			6
# define KEY_X			7
# define KEY_C			8
# define KEY_V			9
# define KEY_SPACE		49
# define KEY_ENTER		36
# define KEY_DEL		51
# define PTR_LEFT		1
# define PTR_RIGHT		2
# define PTR_UP_1		5
# define PTR_UP_2		6
# define PTR_DOWN_1		4
# define PTR_DOWN_2		7

/*
** =============================================================================
** File Descriptor Macros
** =============================================================================
*/

# ifndef OPEN_MAX
#  define OPEN_MAX		4096
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 	1024
# endif

/*
** =============================================================================
** Constant Macros
** =============================================================================
*/

# define DECIMAL		"0123456789"
# define BMP_HEADER		14
# define DIB_HEADER		40
# define IMG_THREAD		8
# define RES_X			1024
# define RES_Y			768
# define N_CAM			4
# define N_OBJ			50
# define N_SAM			2
# define N_DEP			5

/*
** =============================================================================
** Type Definitions
** =============================================================================
*/

typedef int				t_bool;
typedef pthread_mutex_t	t_mux;

typedef struct			s_vec3
{
	double				x;
	double				y;
	double				z;
}						t_vec3;

typedef struct			s_color
{
	double				r;
	double				g;
	double				b;
}						t_color;

typedef struct			s_resolution
{
	int					w;
	int					h;
	double				ar;
}						t_resolution;

typedef struct			s_ambient
{
	double				s;
	t_color				c;
}						t_ambient;

typedef struct			s_camera
{
	t_vec3				p;
	t_vec3				o;
	double				fov;
	t_vec3				hor;
	t_vec3				ver;
	t_vec3				u;
	t_vec3				v;
	t_vec3				w;
	t_vec3				llc;
}						t_camera;

typedef struct			s_light
{
	t_vec3				p;
	double				s;
	t_color				c;
	t_vec3				to;
	double				td;
	t_color				tc;
}						t_light;

typedef	struct			s_sphere
{
	t_vec3				p;
	double				d;
	t_color				c;
	double				r;
	int					m;
}						t_sphere;

typedef struct			s_plane
{
	t_vec3				p;
	t_vec3				n;
	t_color				c;
}						t_plane;

typedef	struct			s_square
{
	t_vec3				p;
	t_vec3				n;
	double				l;
	t_color				c;
}						t_square;

typedef struct			s_cylinder
{
	t_vec3				p;
	t_vec3				o;
	double				d;
	double				h;
	t_color				c;
	double				r;
	t_vec3				tc;
	t_vec3				bc;
}						t_cylinder;

typedef struct			s_triangle
{
	t_vec3				p1;
	t_vec3				p2;
	t_vec3				p3;
	t_color				c;
	t_vec3				p;
	t_vec3				n;
}						t_triangle;

typedef struct			s_cnt
{
	int					r;
	int					a;
	int					c;
	int					l;
	int					sp;
	int					pl;
	int					sq;
	int					cy;
	int					tr;
	int					obj;
}						t_cnt;

typedef struct			s_scene
{
	t_cnt				cnt;
	t_resolution		r;
	t_ambient			a;
	t_camera			*c;
	t_light				*l;
	t_sphere			*sp;
	t_plane				*pl;
	t_square			*sq;
	t_cylinder			*cy;
	t_triangle			*tr;
}						t_scene;

typedef struct			s_obj
{
	int					type;
	int					n;
	void				*data;
	int					filter;
	int					mat;
	double				fuzz;
	double				ir;
}						t_obj;

typedef struct			s_ray
{
	t_vec3				p;
	t_vec3				o;
}						t_ray;

typedef struct			s_hit
{
	t_vec3				p;
	t_vec3				n;
	double				t;
	t_bool				f;
	t_color				c;
	int					mat;
	double				fuzz;
	double				ir;
	double				u_sp;
	double				v_sp;
}						t_hit;

typedef struct			s_img
{
	void				*id;
	char				*addr;
	int					bpp;
	int					sl;
	int					endian;
}						t_img;

typedef struct			s_cur
{
	double				x;
	double				y;
}						t_cur;

typedef struct			s_mlx
{
	void				*sid;
	void				*wid;
	t_scene				rt;
	int					i;
	t_img				*img;
	t_obj				*obj;
	t_cur				p;
	t_cur				r;
}						t_mlx;

typedef struct			s_p
{
	void				*ancestor;
	void				*t;
	void				*p;
	t_mlx				*m;
	t_mux				*l;
	int					i;
	int					x;
}						t_p;

/*
** =============================================================================
** Error Handling Functions
** =============================================================================
*/

void					e_element_dup(void **ptr, int fd);
void					e_element_parse(void **ptr, t_mlx *m, int fd);
void					e_element_identifier(void **ptr, t_mlx *m, int fd);
void					e_element_domain(t_mlx *m);
void					e_file_param(void);
void					e_file_option(void);
void					e_file_extname(void);
void					e_file_open(t_mlx *m);
void					e_file_read(void **ptr, t_mlx *m, int fd);
void					e_memory_alloc(t_mlx *m);
void					e_mlx_setup(t_mlx *m);
void					e_mlx_screen_connection(t_mlx *m);
void					e_mlx_window(t_mlx *m);
void					e_mlx_image(t_mlx *m);
void					e_thread_open(void **t, void **p, t_mlx *m);
void					e_thread_join(void **t, void **p, t_mlx *m);
void					e_thread_alloc(void **t, void **p, t_mlx *m);
void					e_thread_exec(t_p *p, void **t, void **x, t_mux *l);

/*
** =============================================================================
** FT String Functions
** =============================================================================
*/

int						ft_gnl(int fd, char **line);
char					*ft_strdup(const char *s);
char					*ft_strappend(char *s1, char *s2);
void					*ft_memset(void *s, int c, size_t n);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
size_t					ft_strlen(const char *s);
char					*ft_strchr(const char *s, int c);
size_t					ft_strlcpy(char *dst, const char *src, size_t dstsize);

/*
** =============================================================================
** Element Checking Functions
** =============================================================================
*/

t_bool					chk_ambient(t_scene *rt);
t_bool					chk_camera(t_scene *rt);
t_bool					chk_cylinder(t_scene *rt);
t_bool					chk_light(t_scene *rt);
t_bool					chk_plane(t_scene *rt);
t_bool					chk_resolution(t_scene *rt);
t_bool					chk_sphere(t_scene *rt);
t_bool					chk_square(t_scene *rt);
t_bool					chk_triangle(t_scene *rt);

/*
** =============================================================================
** Element Getting Functions
** =============================================================================
*/

t_bool					get_ambient(t_scene *rt, char *line);
t_bool					get_camera(t_scene *rt, char *line);
t_bool					get_cylinder(t_scene *rt, char *line);
t_bool					get_light(t_scene *rt, char *line);
t_bool					get_plane(t_scene *rt, char *line);
t_bool					get_resolution(t_scene *rt, char *line);
t_bool					get_sphere(t_scene *rt, char *line);
t_bool					get_square(t_scene *rt, char *line);
t_bool					get_triangle(t_scene *rt, char *line);

/*
** =============================================================================
** Calc Argument Functions
** =============================================================================
*/

void					p_init(t_p *arg, void *t, void *p, t_mlx *m);
void					p_update(t_p *arg, int i, int x, t_mux *l);

/*
** =============================================================================
** Hooking Functions
** =============================================================================
*/

int						exit_program(t_mlx *m);
int						mouse_press_hook(int key, int x, int y, t_mlx *m);
int						mouse_release_hook(int key, int x, int y, t_mlx *m);
int						key_hook(int key, t_mlx *m);
t_bool					cur_init(int key, double x, double y, t_cur *cur);
t_bool					cam_cur_no_left(int key, t_mlx *m);
t_bool					cam_cur_left(t_mlx *m);
t_bool					cam_key(int key, t_mlx *m);
t_bool					obj_key(int key, t_mlx *m);
t_bool					mode_key(int key, t_mlx *m);

/*
** =============================================================================
** MiniLibX Functions
** =============================================================================
*/

void					*mlx_col_calc(void *p);
void					*mlx_img_calc(void *p);
void					mlx_calc(t_mlx *m);
void					mlx_free(t_mlx *m);
void					mlx_run(t_mlx *m);
void					mlx_write(t_color c, t_p *p, int x, int y);
void					mlx_save(t_mlx *m, char *f, int len);
void					mlx_setup(t_mlx *m, char *f);

/*
** =============================================================================
** Object Functions
** =============================================================================
*/

void					set_hit_color(t_color c, int f, t_hit *rec);
void					set_hit_point(t_ray r, double t, t_hit *rec);
void					set_normal(t_obj obj, t_ray r, t_vec3 n, t_hit *rec);
t_bool					obj_init(t_mlx *m);
t_bool					obj_hit(t_p *p, t_ray r, t_hit *rec, t_bool hit);
t_bool					obj_visible(t_obj *obj, int cnt, t_ray r, double lim);
t_bool					hit_sp(t_obj obj, t_ray r, double lim, t_hit *rec);
t_bool					hit_pl(t_obj obj, t_ray r, double lim, t_hit *rec);
t_bool					hit_sq(t_obj obj, t_ray r, double lim, t_hit *rec);
t_bool					hit_cy(t_obj obj, t_ray r, double lim, t_hit *rec);
t_bool					hit_tr(t_obj obj, t_ray r, double lim, t_hit *rec);
t_bool					interfere_sp(t_obj obj, t_ray r, double lim);
t_bool					interfere_pl(t_obj obj, t_ray r, double lim);
t_bool					interfere_sq(t_obj obj, t_ray r, double lim);
t_bool					interfere_cy(t_obj obj, t_ray r, double lim);
t_bool					interfere_tr(t_obj obj, t_ray r, double lim);

/*
** =============================================================================
** Object Mov Functions
** =============================================================================
*/

void					mov_sp(int key, t_sphere *sp);
void					mov_pl(int key, t_plane *pl);
void					mov_cy(int key, t_cylinder *cy);
void					mov_sq(int key, t_square *sq);
void					mov_tr(int key, t_triangle *tr);
void					obj_mov(int key, t_mlx *m);

/*
** =============================================================================
** Object Rot Functions
** =============================================================================
*/

void					rot_pl(int key, t_plane *pl);
void					rot_cy(int key, t_cylinder *cy);
void					rot_sq(int key, t_square *sq);
void					obj_rot(int key, t_mlx *m);

/*
** =============================================================================
** Parsing Functions
** =============================================================================
*/

int						get_identifier(char **s);
int						get_index(const char *s, int c);
t_bool					udouble(char **s, double *v);
t_bool					sdouble(char **s, double *v1, double *v2, double *v3);
t_bool					uint(char **s, int *v);
t_bool					sint(char **s, int *v1, int *v2, int *v3);

/*
** =============================================================================
** Ray Tracing Math Functions
** =============================================================================
*/

t_ray					r_init(t_vec3 p, t_vec3 o);
t_ray					r_corr(t_p *p, double s, double t);
t_bool					r_lighting(t_mlx *m, t_light *l, t_hit *rec, double *s);
t_color					r_light_color(t_mlx *m, t_light l, t_hit *rec);
t_color					r_trace(t_p *p, t_ray r, int depth);
t_bool					r_scatter(t_ray *r, t_hit *rec);

/*
** =============================================================================
** Scene Functions
** =============================================================================
*/

t_bool					scene_init(t_scene *rt);
void					scene_open(t_mlx *m, char *f, t_bool chk);

/*
** =============================================================================
** Vector Calculation Functions
** =============================================================================
*/

t_vec3					flip(t_vec3 v);
t_vec3					add(t_vec3 u, t_vec3 v);
t_vec3					sub(t_vec3 u, t_vec3 v);
t_vec3					scale(t_vec3 v, double s);

/*
** =============================================================================
** Vector Feature Functions
** =============================================================================
*/

t_vec3					v_init(double x, double y, double z);
t_vec3					unit(t_vec3 v);
t_vec3					reflect(t_vec3 v, t_vec3 n);
t_vec3					refract(t_vec3 uv, t_vec3 n, double etai_over_etat);

/*
** =============================================================================
** Vector Information Functions
** =============================================================================
*/

double					len_pow(t_vec3 v);
double					len_sqrt(t_vec3 v);
t_bool					near_zero(t_vec3 v);
double					dot(t_vec3 u, t_vec3 v);
t_vec3					cross(t_vec3 u, t_vec3 v);

/*
** =============================================================================
** Vector Random Functions
** =============================================================================
*/

t_vec3					v_randr(double min, double max);
t_vec3					v_rand_in_unit_sphere(void);
t_vec3					v_rand_in_unit_hemisphere(t_vec3 n);
t_vec3					v_rand_in_unit_disk(void);
t_vec3					v_rand_unit(void);

/*
** =============================================================================
** BMP Functions
** =============================================================================
*/

t_bool					export_bmp(t_mlx *m, int fd, int idx);

/*
** =============================================================================
** Camera Functions
** =============================================================================
*/

void					cam_mov(int key, t_mlx *m);
void					cam_rot(int key, t_mlx *m);
void					cam_snap(int key, t_mlx *m);
void					cam_init(t_camera *c, t_vec3 up, double ar);

/*
** =============================================================================
** Color Functions
** =============================================================================
*/

t_color					c_init(double r, double g, double b);
t_color					c_add(t_color c1, t_color c2);
t_color					c_mul(t_color c1, t_color c2);
t_color					c_corr(t_color c, int samples_per_pixel);

/*
** =============================================================================
** Math Functions
** =============================================================================
*/

double					randv(void);
double					randr(double min, double max);
double					clamp(double d, double min, double max);
double					degrees_to_radians(double degrees);
double					cosine_to_sine(double cosine);

/*
** =============================================================================
** Memory Functions
** =============================================================================
*/

t_bool					dalloc(void **ptr, size_t cnt, size_t n);
void					free_ptr(void **ptr);
void					free_scene(t_scene *rt);
void					free_thread(void **t, void **p, t_mux *l);

/*
** =============================================================================
** Ostream Functions
** =============================================================================
*/

void					to_string_c(t_camera *c, int idx);
void					ostream_title(const char *s, int idx);
void					ostream_vector(const t_vec3 *v, const char *s);
void					ostream_color(const t_color *c, const char *s);
void					ostream_floating_point(double d, const char *s);

/*
** =============================================================================
** Checking Functions
** =============================================================================
*/

t_bool					is_blank(int c);
t_bool					is_digit(int c);
t_bool					is_endl(const char *s);
t_bool					valid_color(t_color c);
t_bool					valid_vec3(t_vec3 v);

/*
** =============================================================================
** Entry Point
** =============================================================================
*/

void					print_error_list(void);
int						main(int argc, char **argv);

#endif
