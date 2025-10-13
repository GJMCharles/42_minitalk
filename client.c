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

void	send_message(int pid, const char *message)
{
	int				i;
	int				bits;
	unsigned char	c;

	i = 0;
	while (message[i] != '\0')
	{
		bits = 8;
		c = message[i];
		while (bits)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			bits -= 1;
		}
		i += 1;
	}
	kill(pid, SIGUSR2);
}

void	handle_action(int signum)
{
	if (signum == SIGUSR1)
	{
		ft_printf("SIGUSR1 ended\n");
	}
	else if (signum == SIGUSR2)
	{
		ft_printf("SIGUSR2 ended\n");
	}
}

void	process_client(void)
{
	struct sigaction	s_client;

	if (sigemptyset(&s_client.sa_mask) != 0)
		error_found("sigemptyset failed to initialize");
	s_client.sa_flags = SA_SIGINFO;
	s_client.sa_handler = &handle_action;
	if (sigaction(SIGUSR1, &s_client, (void *)0) == -1)
		error_found("sigaction failed for SIGUSR1");
	if (sigaction(SIGUSR2, &s_client, (void *)0) == -1)
		error_found("sigaction failed for SIGUSR2");
}

int	main(int argc, char *argv[])
{
	int		pid;

	(void) argv;
	if (argc != 3)
		error_found("CMD ARG is ≠ 3");
	pid = ft_atoi(argv[1]);
	if (!is_number(argv[1]) || pid <= 0)
		error_found("invalid server PID");
	ft_printf("... %d\n", pid);
	process_client();
	send_message(pid, argv[2]);
	return (EXIT_SUCCESS);
}
