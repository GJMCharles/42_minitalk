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

	i = 0;
	while (message[i] != '\0')
	{
		emit_signal(pid, message[i], 8);
		i += 1;
	}
}

void	handle_response(int signum)
{
	if (signum == SIGUSR1)
		ft_printf("(server) An error has occured.\nPlease contact server admin.\n");
	else if (signum == SIGUSR2)
		ft_printf("Message sent.\n");
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
	s_client.sa_flags = 0;
	s_client.sa_handler = &handle_response;
	if (sigaction(SIGUSR1, &s_client, (void *)0) == -1)
		error_found("sigaction failed for SIGUSR1");
	if (sigaction(SIGUSR2, &s_client, (void *)0) == -1)
		error_found("sigaction failed for SIGUSR2");
	emit_signal(pid, ft_strlen(argv[2]), 32);
	send_message(pid, argv[2]);
	return (EXIT_SUCCESS);
}
