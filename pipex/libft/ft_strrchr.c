/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:00:23 by mingkang          #+#    #+#             */
/*   Updated: 2022/11/09 17:30:09 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	while (*ptr != 0)
		ptr++;
	while (1)
	{
		if (*ptr == (char)c)
			return (ptr);
		if (ptr == s)
			return (0);
		ptr--;
	}
}
