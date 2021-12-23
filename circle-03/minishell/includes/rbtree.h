/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:35:07 by jseo              #+#    #+#             */
/*   Updated: 2021/12/23 18:09:44 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_H
# define RBTREE_H

/*
** =============================================================================
** Dependencies from System
** =============================================================================
*/

# include <stdio.h>

/*
** =============================================================================
** Dependencies from User
** =============================================================================
*/

# include "j_function.h"
# include "enumeration.h"

/*
** =============================================================================
** Enum Type Definitions
** =============================================================================
*/

typedef enum e_color
{
	RED,
	BLACK,
}					t_color;

typedef enum e_order
{
	PREORDER,
	INORDER,
	POSTORDER,
}					t_order;

/*
** =============================================================================
** Struct Type Definitions
** =============================================================================
*/

typedef struct s_rb
{
	char			*key;
	char			*val;
	size_t			k_len;
	size_t			v_len;
	t_color			c;
	struct s_rb		*l;
	struct s_rb		*r;
	struct s_rb		*p;
}					t_rb;

/*
** =============================================================================
** RB Delete Functions
** =============================================================================
*/

void	rb_d_recolor_left(t_rb **t, t_rb **x, t_rb **cousin, t_rb **parent);
void	rb_d_recolor_right(t_rb **t, t_rb **x, t_rb **cousin, t_rb **parent);
void	rb_d_fixup(t_rb **t, t_rb **x);
void	rb_d_both_child(t_rb **t, t_rb **z, t_rb **y, t_rb **x);
t_rb	*rb_delete(t_rb *t, t_rb *z);

/*
** =============================================================================
** RB Insert Functions
** =============================================================================
*/

bool	rb_new(t_rb **rb, char *key, char *val);
void	rb_i_recolor(t_rb **t, t_rb **z, t_rb **parent, t_rb **grandparent);
void	rb_i_fixup(t_rb **t, t_rb **z);
t_rb	*rb_insert(t_rb *t, char *key, char *val);

/*
** =============================================================================
** RB LookUp Functions
** =============================================================================
*/

void	rb_order(t_rb *root, t_order order);
t_rb	*rb_search(t_rb *root, char *key);
t_rb	*rb_min(t_rb *root);
t_rb	*rb_max(t_rb *root);

/*
** =============================================================================
** RB Utility Functions
** =============================================================================
*/

void	rb_clear(t_rb **root);
bool	rb_left(t_rb **t, t_rb **x);
bool	rb_right(t_rb **t, t_rb **x);
void	rb_transplant(t_rb **t, t_rb **u, t_rb **v);

#endif
