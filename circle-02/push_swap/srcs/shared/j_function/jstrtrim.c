/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jstrtrim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:56:34 by jseo              #+#    #+#             */
/*   Updated: 2021/06/09 22:45:11 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void	jstrtrim(char **s)
{
	size_t len;

	while (jisspace(**s))
		++(*s);
	len = jstrlen(*s);
	while (jisspace((*s)[len - 1]))
		--len;
	(*s)[len] = '\0';
}