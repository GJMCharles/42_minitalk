/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 22:10:22 by grcharle          #+#    #+#             */
/*   Updated: 2025/09/29 22:10:46 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	emit_signal(int pid, unsigned int c, unsigned int bits)
{
	while (bits)
	{
		if (c >> (bits - 1) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(200);
		bits -= 1;
	}
}

void	send_message(int pid, const char *message)
{
	int				i;

	i = 0;
	while (message[i] != '\0')
	{
		emit_signal(pid, message[i], 8);
		i += 1;
	}
}

void	response_handler(int signum)
{
	if (signum == SIGUSR1)
		ft_printf("SIGUSR1 ended\n");
	else if (signum == SIGUSR2)
		ft_printf("SIGUSR2 ended\n");
}

int	main(int argc, char *argv[])
{
	struct sigaction	s_client;
	int		pid;

	(void) argv;
	if (argc != 3)
		error_found("CMD ARG is ≠ 3");
	if (!is_number(argv[1]))
		error_found("invalid argument for server PID");
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		error_found("invalid server PID");
	if (sigemptyset(&s_client.sa_mask) != 0)
		error_found("sigemptyset failed to initialize");
	s_client.sa_flags = SA_SIGINFO;
	s_client.sa_handler = &response_handler;
	if (sigaction(SIGUSR1, &s_client, (void *)0) == -1)
		error_found("sigaction failed for SIGUSR1");
	if (sigaction(SIGUSR2, &s_client, (void *)0) == -1)
		error_found("sigaction failed for SIGUSR2");
	emit_signal(pid, ft_strlen(argv[2]), 32);
	send_message(pid, argv[2]);
	return (EXIT_SUCCESS);
}
