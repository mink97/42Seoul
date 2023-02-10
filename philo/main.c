/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkang <mingkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:37:40 by mingkang          #+#    #+#             */
/*   Updated: 2023/02/09 16:08:44 by mingkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_info	info;
	t_philo	*philos;
	int		i;

	if (argc < 5 || argc > 6)
	{
		printf("Error\n");
		return (-1);
	}
	if (init_info(argv, &info) == -1)
	{
		printf("Error\n");
		return (-1);
	}
	init_philo(&info, &philos);
	i = 0;
	while (i < info.num_philos)
	{
		if (i % 2 == 0)
			pthread_create(&philos[i].ph_thread, NULL, routine, (void *)&philos[i]);
		i++;
	}
	usleep(200);
	i = 0;
	while (i < info.num_philos)
	{
		if (i % 2 != 0)
			pthread_create(&philos[i].ph_thread, NULL, routine, (void *)&philos[i]);
		i++;
	}
	i = 0;
	while (i < info.num_philos)
	{
		pthread_join(philos[i].ph_thread, NULL);
		i++;
	}
}
