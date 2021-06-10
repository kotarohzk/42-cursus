/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jlstdelone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 15:18:37 by jseo              #+#    #+#             */
/*   Updated: 2021/06/10 14:00:17 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	jlstdelone(t_list **lst)
{
	if (!lst)
		return ;
	(*lst)->p = NULL;
	(*lst)->n = NULL;
	jfree((void **)(lst));
}