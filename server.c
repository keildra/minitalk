/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarali <ekarali@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 23:31:28 by ekarali           #+#    #+#             */
/*   Updated: 2022/06/14 00:12:22 by ekarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// getting the bits and printing them on the terminal when it is a valid char
// also sending a signal back to client to say the string has been received
void	sfed(int signum, siginfo_t *s, void *unused)
{
	static int		ch;
	static int		n = 128;
	unsigned int	c;

	(void)unused;
	if (signum == SIGUSR1)
		c = 1;
	else
		c = 0;
	ch = ch + n * c;
	if (n == 1)
	{
		if (ch == '\0')
		{
			if (kill(s->si_pid, SIGUSR1) == -1)
				ft_putstr("where's the rest?");
		}
		write(1, &ch, 1);
		ch = 0;
		n = 128;
		c = 0;
	}
	else
		n = n / 2;
}

// decides the flags and fills the s struct with necessary information
int	main(void)
{
	struct sigaction	s;

	ft_putstr("server pid: ");
	ft_putnbr(getpid());
	ft_putstr("\n");
	s.sa_flags = SA_SIGINFO;
	s.sa_sigaction = sfed;
	if (sigaction(SIGUSR1, &s, NULL) == -1)
		ft_putstr("oh no\n");
	if (sigaction(SIGUSR2, &s, NULL) == -1)
		ft_putstr("oh no\n");
	while (1)
		pause();
	return (0);
}
