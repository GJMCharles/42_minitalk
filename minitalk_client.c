/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 14:53:54 by grcharle          #+#    #+#             */
/*   Updated: 2025/08/28 14:35:55 by grcharle         ###   ########.fr       */
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

int		main(int argc, char *argv[])
{
	struct sigaction sa;
	sa.sa_flags = SIGINT;
	sa.sa_handler = &signal_handler;
	return (0);
}
