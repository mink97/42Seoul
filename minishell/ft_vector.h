/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbok <jbok@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 09:29:00 by jbok              #+#    #+#             */
/*   Updated: 2023/01/29 14:08:48 by jbok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

# include "libft.h"

# ifndef VEC_RESERVE_SIZE
#  define VEC_RESERVE_SIZE 16
# endif

typedef struct s_vector
{
	char	*content;
	ssize_t	size;
	ssize_t	capacity;
}	t_vector;

t_vector	*ft_vec_new(void);
t_vector	*ft_vec_del(t_vector *vec);
ssize_t		ft_vec_push(t_vector *vec, char content);
char		ft_vec_pop(t_vector *vec);
int			ft_vec_reserve(t_vector *vec, ssize_t size);

#endif