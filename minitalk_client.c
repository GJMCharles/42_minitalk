/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 14:53:54 by grcharle          #+#    #+#             */
/*   Updated: 2025/08/23 18:22:43 by grcharle         ###   ########.fr       */
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

void	handle_sigtsps(int sig)
{
	(void) sig;
	//
}

int	main(int argc, char *argv[])
{
	(void) argc;
	(void) argv;
	pid_t	pid;

	struct sigaction sa = { 0 };
	sa.sa_handler = &handle_sigtsps;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGTSTP, &sa, NULL);

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
	else
	{
		//
	}
	sleep(5);
	kill(pid, SIGKILL);
	return (0);
}
