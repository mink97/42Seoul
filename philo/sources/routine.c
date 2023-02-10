/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 09:25:22 by mingkang          #+#    #+#             */
/*   Updated: 2023/02/10 16:41:54 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_dead(t_philo *philo, t_info *info, int now_time)
{
	pthread_mutex_lock(&info->dead_mutex);
	if (info->is_dead == 0)
	{
		info->is_dead = 1;
		pthread_mutex_lock(&info->text_mutex);
		printf("%d %d is died\n", now_time - info->start_time, philo->num);
		pthread_mutex_unlock(&info->text_mutex);
	}
	pthread_mutex_unlock(&info->dead_mutex);
}

int	pickup_fork(t_philo *philo, t_info *info, t_fork *fork)
{
	int	now_time;

	if (gettime(&now_time) != 0)
		return (-1);
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
		if (gettime(&now_time) != 0)
			return (-1);
	}
	if (gettime(&now_time) != 0)
		return (-1);
	if (now_time - philo->last_eat_time >= info->tm_die)
		philo_dead(philo, info, now_time);
	else if (print_status(philo, info, TAKE_FORK) != 0)
		return (-1);
	return (0);
}

void	putdown_fork(t_fork *fork)
{
	pthread_mutex_lock(&fork->fork_mutex);
	fork->status = 0;
	pthread_mutex_unlock(&fork->fork_mutex);
}

int	try_eat(t_philo *philo, t_info *info)
{
	if (pickup_fork(philo, info, philo->left_fork) != 0)
		return (-1);
	if (pickup_fork(philo, info, philo->right_fork) != 0)
		return (-1);
	if (print_status(philo, info, EATING) != 0)
		return (-1);
	philo->eat_count--;
	if (gettime(&philo->last_eat_time) != 0)
		return (-1);
	if (ft_sleep(philo, info, info->tm_eat) != 0)
		return (-1);
	putdown_fork(philo->right_fork);
	putdown_fork(philo->left_fork);
	return (0);
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
		if (try_eat(philo, info) != 0)
			return (NULL);
		if (print_status(philo, info, SLEEPING) != 0)
			return (NULL);
		if (ft_sleep(philo, info, info->tm_sleep) != 0)
			return (NULL);
		if (print_status(philo, info, THINKING) != 0)
			return (NULL);
	}
	return ((void *)philo);
}
