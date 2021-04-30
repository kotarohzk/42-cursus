/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 15:00:38 by jseo              #+#    #+#             */
/*   Updated: 2021/04/28 18:07:39 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	hit_cy(t_obj obj, t_ray r, double lim, t_hit *rec)
{
	void	*p1;
	void	*p2;
	void	*p3;
	void	*p4;

	p1 = &obj;
	p2 = &r;
	p3 = &lim;
	p4 = rec;
	return (FALSE);
}

t_bool	interfere_cy(t_obj obj, t_ray r, double lim)
{
	void *p1;
	void *p2;
	void *p3;

	p1 = &obj;
	p2 = &r;
	p3 = &lim;
	return (TRUE);
}