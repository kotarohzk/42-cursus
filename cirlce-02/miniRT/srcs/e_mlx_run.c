/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_mlx_run.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:55:25 by jseo              #+#    #+#             */
/*   Updated: 2021/04/21 14:44:37 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	e_mlx_run(t_scene *rt)
{
	errno = 85;
	perror("Type: Cannot run mlx\nerrno 85");
	printf("Error\n");
	free_scene(rt);
	exit(INVALID);
}
