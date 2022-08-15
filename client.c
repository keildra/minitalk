/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarali <ekarali@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 23:31:14 by ekarali           #+#    #+#             */
/*   Updated: 2022/06/14 00:04:17 by ekarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// sending chars bit by bit
void	sendbits(int pid, int c)
{
	int	n;

	n = 128;
	while (n >= 1)
	{
		if (c / n == 1)
		{
			kill(pid, SIGUSR1);
			c = c % n;
		}
		else
			kill(pid, SIGUSR2);
		n = n / 2;
		usleep(100);
	}
}

// action taken when the signal from the server comes
void	sfeedback(int signum)
{
	(void)signum;
	ft_putstr("'nom nom nom'");
}

// takes the pid and the string to send and sends it letter by letter
int	main(int argc, char **argv)
{
	int				i;
	unsigned char	*str;

	str = (unsigned char *)argv[2];
	if (signal(SIGUSR1, sfeedback) == SIG_ERR)
		ft_putstr("'no signal? me hungry!' client hears server say\n");
	if (argc == 3)
	{	
		i = 0;
		while (str[i])
			sendbits(ft_atoi(argv[1]), str[i++]);
		sendbits(ft_atoi(argv[1]), '\0');
	}
	else
		ft_putstr("usage: ./client [server pid] [string to send]");
}
