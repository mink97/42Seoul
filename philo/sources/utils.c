/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:07:05 by mingkang          #+#    #+#             */
/*   Updated: 2023/02/10 16:42:55 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <limits.h>

int	gettime(int *time)
{
	struct timeval	timeval;

	if (gettimeofday(&timeval, NULL) == -1)
		return (-1);
	*time = timeval.tv_sec * 1000 + timeval.tv_usec / 1000;
	return (0);
}

int	check_dead(t_info *info)
{
	pthread_mutex_lock(&info->dead_mutex);
	if (info->is_dead == 1)
	{
		pthread_mutex_unlock(&info->dead_mutex);
		return (1);
	}
	else
	{
		pthread_mutex_unlock(&info->dead_mutex);
		return (0);
	}
}

int	ft_sleep(t_philo *philo, t_info *info, int ml_sec)
{
	int	now_time;
	int	start_time;

	if (gettime(&now_time) != 0)
		return (-1);
	if (gettime(&start_time) != 0)
		return (-1);
	while (now_time - start_time < ml_sec && \
			now_time - philo->last_eat_time < info->tm_die)
	{
		usleep(500);
		if (gettime(&now_time) != 0)
			return (-1);
	}
	if (now_time - philo->last_eat_time >= info->tm_die)
		philo_dead(philo, info, now_time);
	return (0);
}

int	print_status(t_philo *philo, t_info *info, t_status status)
{
	int	time;
	int	now_time;

	if (gettime(&now_time) != 0)
		return (-1);
	time = now_time - info->start_time;
	pthread_mutex_lock(&info->dead_mutex);
	if (info->is_dead == 1)
	{
		pthread_mutex_unlock(&info->dead_mutex);
		return (0);
	}
	pthread_mutex_unlock(&info->dead_mutex);
	pthread_mutex_lock(&info->text_mutex);
	if (status == TAKE_FORK)
		printf("%d %d has taken a fork\n", time, philo->num);
	else if (status == EATING)
		printf("%d %d is eating\n", time, philo->num);
	else if (status == SLEEPING)
		printf("%d %d is sleeping\n", time, philo->num);
	else if (status == THINKING)
		printf("%d %d is thinking\n", time, philo->num);
	pthread_mutex_unlock(&info->text_mutex);
	return (0);
}

size_t	ft_atoi_philo(const char *str)
{
	int				i;
	unsigned long	num;

	i = 0;
	num = 0;
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (num > ULONG_MAX / 10 || \
			(num == ULONG_MAX && (str[i] - '0') > (int)(ULONG_MAX % 10)))
			return (0);
		num = num * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
		return (0);
	return ((size_t)num);
}
