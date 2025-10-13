/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:11:15 by grcharle          #+#    #+#             */
/*   Updated: 2025/09/30 17:12:51 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	error_found(char *message)
{
	ft_printf("Error: %s\n", message);
	exit(EXIT_FAILURE);
}

void	emit_signal(int pid, unsigned int c, unsigned int bits)
{
	unsigned int	i;

	i = 0;
	while (i < bits)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i += 1;
	}
}