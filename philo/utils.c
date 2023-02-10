/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:07:05 by mingkang          #+#    #+#             */
/*   Updated: 2023/02/10 12:43:55 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <limits.h>

int	gettime(void)
{
	struct timeval	timeval;
	int				time;

	if (gettimeofday(&timeval, NULL) == -1)
		return (-1);
	time = timeval.tv_sec * 1000 + timeval.tv_usec / 1000;
	return (time);
}

int	check_dead(t_info *info)
{
	int	is_dead;

	pthread_mutex_lock(&info->dead_mutex);
	if (info->is_dead == 1)
		is_dead = 1;
	else
		is_dead = 0;
	pthread_mutex_unlock(&info->dead_mutex);
	return (is_dead);
}

void	ft_sleep(t_philo *philo, t_info *info, int ml_sec)
{
	int	now_time;
	int	start_time;

	now_time = gettime();
	start_time = gettime();
	while (now_time - start_time < ml_sec && \
			now_time - philo->last_eat_time < info->tm_die)
	{
		usleep(500);
		now_time = gettime();
	}
	if (now_time - philo->last_eat_time >= info->tm_die) // 죽음.
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
}

void	print_status(t_philo *philo, t_info *info, t_status status)
{
	int	time;

	time = gettime() - info->start_time;
	pthread_mutex_lock(&info->dead_mutex);
	if (info->is_dead == 1)
	{
		pthread_mutex_unlock(&info->dead_mutex);
		return ;
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
			(num == ULONG_MAX && (str[i] - '0') > ULONG_MAX % 10))
			return (0);
		num = num * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
		return (0);
	return ((size_t)num);
}
