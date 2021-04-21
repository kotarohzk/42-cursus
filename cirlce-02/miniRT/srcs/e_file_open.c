/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_file_open.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 13:12:29 by jseo              #+#    #+#             */
/*   Updated: 2021/04/21 19:58:48 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	e_file_open(t_scene *rt)
{
	errno = 9;
	perror("Type: File open\nerrno 9");
	printf("Error\n");
	free_scene(rt);
	exit(INVALID);
}
