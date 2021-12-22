/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jcalloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:41:41 by jseo              #+#    #+#             */
/*   Updated: 2021/12/22 17:47:32 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	jcalloc(void **ptr, size_t cnt, size_t n)
{
	*ptr = (void *)malloc(cnt * n);
	if (!*ptr)
		return (false);
	jmemset(*ptr, 0, cnt * n);
	return (true);
}
