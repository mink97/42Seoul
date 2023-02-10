/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 09:25:38 by mingkang          #+#    #+#             */
/*   Updated: 2023/02/10 12:45:10 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <limits.h>

int	init_fork(t_info *info)
{
	int	i;

	info->forks = malloc(sizeof(t_fork) * info->num_philos);
	if (info->forks == NULL)
		return (-1);
	i = 0;
	while (i < info->num_philos)
	{
		(info->forks + i)->status = 0;
		if (pthread_mutex_init(&(info->forks + i)->fork_mutex, NULL) != 0)
		{
			free(info->forks);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	init_info(char **argv, t_info *info)
{
	pthread_mutex_init(&info->dead_mutex, NULL);
	pthread_mutex_init(&info->text_mutex, NULL);
	info->is_dead = 0;
	info->num_philos = ft_atoi_philo(argv[1]);
	if (info->num_philos == 0)
		return (-1);
	info->tm_die = ft_atoi_philo(argv[2]);
	if (info->tm_die == 0)
		return (-1);
	info->tm_eat = ft_atoi_philo(argv[3]);
	if (info->tm_eat == 0)
		return (-1);
	info->tm_sleep = ft_atoi_philo(argv[4]);
	if (info->tm_sleep == 0)
		return (-1);
	if (argv[5] == NULL)
		info->eat_count = SIZE_MAX;
	else
		info->eat_count = ft_atoi_philo(argv[5]);
	if (info->eat_count == 0)
		return (-1);
	if (init_fork(info) != 0)
		return (-1);
	info->start_time = gettime();
	return (0);
}

int	init_philo(t_info *info, t_philo **philo_arr)
{
	int		i;

	*philo_arr = malloc(sizeof(t_philo) * info->num_philos);
	i = 0;
	while (i < info->num_philos)
	{
		(*philo_arr)[i].num = i;
		(*philo_arr)[i].last_eat_time = info->start_time;
		(*philo_arr)[i].eat_count = info->eat_count;
		(*philo_arr)[i].left_fork = &info->forks[i];
		(*philo_arr)[i].right_fork = &info->forks[(i + 1) % info->num_philos];
		(*philo_arr)[i].info = info;
		i++;
	}
	return (0);
}
