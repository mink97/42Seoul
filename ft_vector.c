/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbok <jbok@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 09:33:45 by jbok              #+#    #+#             */
/*   Updated: 2023/02/03 20:36:05 by jbok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vector	*ft_vec_new(void)
{
	t_vector	*ptr;

	ptr = malloc_check(sizeof(t_vector));
	ptr->content = malloc_check(sizeof(char) * VEC_RESERVE_SIZE);
	ptr->size = 0;
	ptr->capacity = VEC_RESERVE_SIZE;
	return (ptr);
}

t_vector	*ft_vec_del(t_vector *vec)
{
	if (!vec)
		return (0);
	if (vec->content)
		free(vec->content);
	free(vec);
	return (0);
}

ssize_t	ft_vec_push(t_vector *vec, char content)
{
	ssize_t	cap;

	if (vec->size == vec->capacity)
	{
		cap = vec->capacity + vec->capacity / 2;
		vec->content = ft_realloc(vec->content, sizeof(char) * vec->size, \
		sizeof(char) * (vec->capacity + vec->capacity / 2));
		if (!(vec->content))
			return (-1);
		vec->capacity = cap;
	}
	(vec->content)[vec->size++] = content;
	return (vec->size);
}

int	ft_vec_reserve(t_vector *vec, ssize_t size)
{
	vec->content = ft_realloc(vec->content, sizeof(char) * vec->size, \
	sizeof(char) * size);
	if (!(vec->content))
		return (-1);
	vec->capacity = size;
	return (0);
}

char	ft_vec_pop(t_vector *vec)
{
	if (vec->size == 0)
		return (0);
	else
		return ((vec->content)[--(vec->size)]);
}
