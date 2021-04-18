/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_file_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 13:12:29 by jseo              #+#    #+#             */
/*   Updated: 2021/04/18 15:25:57 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	e_file_read(void)
{
	errno = 45;
	perror("ERROR SPEC: file read\nerrno 45");
	printf("Error\n");
	exit(INVALID);
}
