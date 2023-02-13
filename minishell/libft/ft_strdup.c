/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbok <jbok@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:27:13 by jbok              #+#    #+#             */
/*   Updated: 2023/02/03 20:38:38 by jbok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*dst;
	int		len;

	if (!src)
		return (ft_strdup("(null)"));
	len = ft_strlen(src);
	dst = malloc_check(len + 1);
	ft_memcpy(dst, src, len + 1);
	return (dst);
}
