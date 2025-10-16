/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 22:10:16 by grcharle          #+#    #+#             */
/*   Updated: 2025/09/29 22:12:41 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "ft_printf.h"

typedef struct s_data
{
	unsigned int	pid;	// client process ID
	unsigned int	count;	// signal count received
	unsigned int	pos;	// binary position [0...8]
	unsigned int	index;	// index for message character
	char			*text;	// message
	struct s_data *next;
}	t_data;

void	error_found(char *message);
void	init_signal(struct sigaction *sig, void (fcall)(struct sigaction *sig));

#endif // MINITALK_H
