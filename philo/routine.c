/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 09:25:22 by mingkang          #+#    #+#             */
/*   Updated: 2023/02/10 12:43:48 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pickup_fork(t_philo *philo, t_info *info, t_fork *fork)
{
	int	now_time;

	now_time = gettime();
	while (now_time - philo->last_eat_time < info->tm_die)
	{
		pthread_mutex_lock(&fork->fork_mutex);
		if (fork->status == 0)
		{
			fork->status = 1;
			pthread_mutex_unlock(&fork->fork_mutex);
			break ;
		}
		pthread_mutex_unlock(&fork->fork_mutex);
		usleep(50);
		now_time = gettime();
	}
	if (gettime() - philo->last_eat_time >= info->tm_die) // 죽음.
	{
		pthread_mutex_lock(&info->dead_mutex);
		if (info->is_dead == 0)
		{
			info->is_dead = 1;
			pthread_mutex_lock(&info->text_mutex);
			printf("%d %d is died\n", gettime() - info->start_time, philo->num);
			pthread_mutex_unlock(&info->text_mutex);
		}
		pthread_mutex_unlock(&info->dead_mutex);
	}
	print_status(philo, info, TAKE_FORK);
}

void	putdown_fork(t_fork *fork)
{
	pthread_mutex_lock(&fork->fork_mutex);
	fork->status = 0;
	pthread_mutex_unlock(&fork->fork_mutex);
}

void	try_eat(t_philo *philo, t_info *info)
{
	pickup_fork(philo, info, philo->left_fork);
	pickup_fork(philo, info, philo->right_fork);
	print_status(philo, info, EATING);
	philo->eat_count--;
	philo->last_eat_time = gettime();
	ft_sleep(philo, info, info->tm_eat);
	putdown_fork(philo->right_fork);
	putdown_fork(philo->left_fork);
}

void	*routine(void *data)
{
	int		i;
	t_philo	*philo;
	t_info	*info;

	philo = (t_philo *)data;
	info = philo->info;
	i = 0;
	while (philo->eat_count > 0 && check_dead(info) == 0)
	{
		try_eat(philo, info);
		print_status(philo, info, SLEEPING);
		ft_sleep(philo, info, info->tm_sleep);
		print_status(philo, info, THINKING);
	}
	return ((void *)philo);
}
