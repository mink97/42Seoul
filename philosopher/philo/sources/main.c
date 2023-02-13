/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:37:40 by mingkang          #+#    #+#             */
/*   Updated: 2023/02/10 17:00:06 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_philo(t_philo *philos, t_info *info, size_t i)
{
	i = -1;
	while (++i < info->num_philos)
	{
		if ((i & 1) == 0 && \
			pthread_create(&philos[i].ph_thr, 0, routine, (void *)&philos[i]))
		{
			free(info->forks);
			free(philos);
			return (-1);
		}
	}
	usleep(200);
	i = -1;
	while (++i < info->num_philos)
	{
		if ((i & 1) != 0 && \
			pthread_create(&philos[i].ph_thr, 0, routine, (void *)&philos[i]))
		{
			free(info->forks);
			free(philos);
			return (-1);
		}
	}
	return (0);
}

int	join_thread(t_philo *philos, t_info *info)
{
	size_t	i;

	i = -1;
	while (++i < info->num_philos)
	{
		if (pthread_join(philos[i].ph_thr, NULL))
		{
			free(info->forks);
			free(philos);
			return (-1);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_info	info;
	t_philo	*philos;
	size_t	i;

	i = 0;
	if (argc < 5 || argc > 6)
	{
		printf("argument Error\n");
		return (-1);
	}
	if (init_info(argv, &info) == -1 || init_philo(&info, &philos) == -1)
	{
		printf("initializing Error\n");
		return (-1);
	}
	if (create_philo(philos, &info, i) != 0 || join_thread(philos, &info) != 0)
	{
		printf("pthread Error\n");
		return (-1);
	}
	free(info.forks);
	free(philos);
	return (0);
}
