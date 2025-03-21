/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:16:47 by mingkang          #+#    #+#             */
/*   Updated: 2023/02/10 16:43:13 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef enum e_status
{
	TAKE_FORK,
	EATING,
	SLEEPING,
	THINKING,
	DEAD
}	t_status;

typedef struct s_info
{
	size_t			num_philos;
	size_t			eat_count;
	int				tm_die;
	int				tm_eat;
	int				tm_sleep;
	int				is_dead;
	int				start_time;
	struct s_fork	*forks;
	pthread_mutex_t	dead_mutex;
	pthread_mutex_t	text_mutex;
}	t_info;

typedef struct s_fork
{
	int				status;
	pthread_mutex_t	fork_mutex;
}	t_fork;

typedef struct s_philo
{
	int			num;
	int			last_eat_time;
	size_t		eat_count;
	pthread_t	ph_thr;
	t_fork		*left_fork;
	t_fork		*right_fork;
	t_info		*info;
}	t_philo;

size_t	ft_atoi_philo(const char *str);
int		init_info(char **argv, t_info *info);
int		init_fork(t_info *info);
int		init_philo(t_info *info, t_philo **philo_arr);
void	*routine(void *data);
int		gettime(int *time);
int		print_status(t_philo *philo, t_info *info, t_status status);
int		check_dead(t_info *info);
int		ft_sleep(t_philo *philo, t_info *info, int ml_sec);
void	philo_dead(t_philo *philo, t_info *info, int now_time);

#endif
