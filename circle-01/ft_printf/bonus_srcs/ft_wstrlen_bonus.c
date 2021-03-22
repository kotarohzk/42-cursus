/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 14:08:43 by jseo              #+#    #+#             */
/*   Updated: 2021/03/22 09:26:30 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

size_t	ft_wstrlen(wchar_t *s)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	while (s[i])
	{
		if (s[i] >= 0 && s[i] <= 127)
			size += 1;
		else if (s[i] >= 128 && s[i] <= 2047)
			size += 2;
		else if (s[i] >= 2048 && s[i] <= 65535)
			size += 3;
		else if (s[i] >= 65535 && s[i] <= 2097151)
			size += 4;
		++i;
	}
	return (size);
}
