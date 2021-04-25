/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifier.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 13:13:26 by jseo              #+#    #+#             */
/*   Updated: 2021/04/25 15:19:00 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	get_identifier(char **s)
{
	int	i;

	i = get_index("RAcl", (*s)[0]);
	if (i > 0 && is_blank((*s)[1]))
		return (i);
	i = get_index("spct", (*s)[0]);
	if (i > 0)
	{
		i = get_index("plqyr", (*s)[1]);
		if (i > 0 && is_blank((*s)[2]))
			return (i + 4);
	}
	return (0);
}