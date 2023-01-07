/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:55:52 by mingkang          #+#    #+#             */
/*   Updated: 2022/11/09 17:22:19 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	while (1)
	{
		if (*ptr == (char)c)
			return (ptr);
		if (!(*ptr))
			return (0);
		ptr++;
	}
}
