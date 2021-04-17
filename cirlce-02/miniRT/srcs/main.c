/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:24:34 by jseo              #+#    #+#             */
/*   Updated: 2021/04/17 16:24:35 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	pre_setting(t_mlx *m)
{
	m->sid = mlx_init();
	m->wid = mlx_new_window(m->sid, 400, 300, "miniRT");
}

t_bool	parse_scene(t_mlx *m)
{
	m->data->x = 0;
	m->data->y = 1;
	return (TRUE);
}

int		main(int argc, char **argv)
{
	t_mlx	m;

	if (argc != 2 || !parse_scene(&m))
		return (ERROR);
	pre_setting(&m);
	mlx_loop(m.sid);
	return (SUCCESS);
}
