/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbok <jbok@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:14:43 by bok               #+#    #+#             */
/*   Updated: 2023/02/03 20:35:17 by jbok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEQUE_H
# define FT_DEQUE_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_dlist
{
	void			*content;
	struct s_dlist	*prev;
	struct s_dlist	*next;
}	t_dlist;

typedef struct s_deque
{
	t_dlist			*front;
	t_dlist			*rear;
	size_t			size;
}	t_deque;

//	deque.c
size_t	ft_pushback(t_deque *deque, void *content);
size_t	ft_pushfront(t_deque *deque, void *content);
void	*ft_popback(t_deque *deque);
void	*ft_popfront(t_deque *deque);

#endif
