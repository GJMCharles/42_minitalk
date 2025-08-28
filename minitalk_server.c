/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_server.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 14:53:54 by grcharle          #+#    #+#             */
/*   Updated: 2025/08/25 13:18:18 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
write
ft_printf
signal
sigemptyset
sigaddset
sigaction
kill
getpid
malloc
free
pause
sleep
usleep
exit
*/

void	signal_handler(int sig)
{
	(void) sig;
	//
}

int	main(int argc, char *argv[])
{
	(void) argc;
	(void) argv;

	struct sigaction sa;
	sa.sa_flags = SIGINT;
	sa.sa_handler = &signal_handler;
	if (sigaction(SIGUSR1, &sa, NULL))
	{
		//
	}
	if (sigaction(SIGUSR2, &sa, NULL))
	{
		//
	}

	pid_t	pid;

	pid = fork();
	if (pid < 0)
		return (1);
	if (pid == 0)
	{
		while (1)
		{
			ft_printf("Some text goes here\n");
			sleep(1);
		}
	}
	sleep(5);
	kill(pid, SIGKILL);
	return (0);
}
