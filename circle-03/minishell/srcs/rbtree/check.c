/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 21:51:48 by jseo              #+#    #+#             */
/*   Updated: 2021/12/23 22:31:53 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rbtree.h"

/*
** rb_assert ()			- Assert Whether Condition True or False
**
** return				- void
** condition			- Condition to Check
** context				- Context Information in Runtime
*/

void	rb_assert(bool condition, char *context)
{
	if (condition)
		return ;
	printf("%s\n", context);
	exit(GENERAL);
}

/*
** is_root ()			- Check Whether the Node Equal to Root
**
** return				- True or False
** node					- Specific Node
*/

bool	is_root(t_node *node)
{
	rb_assert(node != NULL, \
		ASSERT "(node != NULL), " IS_ROOT RB_CHECK "line 40.");
	return (get_parent(node) == NULL);
}

/*
** is_black ()			- Check the Color of the Node Equal to Black
**
** return				- True of False
** node					- Specific Node
*/

bool	is_black(t_node *node)
{
	rb_assert(node != NULL, \
		ASSERT "(node != NULL), " IS_BLACK RB_CHECK "line 54.");
	return (get_color(node) == BLACK);
}

/*
** is_red ()			- Check the Color of the Node Equal to Red
**
** return				- True or False
** node					- Specific Node
*/

bool	is_red(t_node *node)
{
	rb_assert(node != NULL, \
		ASSERT "(node != NULL), " IS_RED RB_CHECK "line 69.");
	return (get_color(node) == RED);
}
