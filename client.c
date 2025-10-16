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

void	send_message(unsigned int spid, const char *message)
{
	unsigned int	i;

	while (*message)
	{
		i = 0;
		while (i++ < 8)
		{
			usleep(100);
			if ((unsigned char)*message >> (i - 1) & 1)
			{
				if (kill(spid, SIGUSR1) == -1)
					error_found("failed to send signal SIGUSR1");
			}
			else
			{
				if (kill(spid, SIGUSR2) == -1)
					error_found("failed to send signal SIGUSR2");
			}
			pause();
		}
		message += 1;
	}
	exit(EXIT_SUCCESS);
}

void	handle_response(int signum)
{
	if (signum == SIGUSR2)
		error_found("(server) An error has occured.");
}

int	is_number(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i += 1;
	}
	return (1);
}

void	init_callback(struct sigaction *client_sig)
{
	client_sig->sa_flags = 0;
	client_sig->sa_handler = &handle_response;
}

int	main(int argc, char *argv[])
{
	struct sigaction	s_client;
	unsigned int		pid;

	(void) argc;
	if (argc != 3)
		error_found("CMD ARG is ≠ 3");
	if (!is_number(argv[1]))
		error_found("invalid argument for server PID");
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		error_found("invalid server PID");
	init_signal(&s_client, init_callback);
	send_message(pid, argv[2]);
	return (EXIT_SUCCESS);
}
