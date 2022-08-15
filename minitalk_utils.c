/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarali <ekarali@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 21:47:25 by ekarali           #+#    #+#             */
/*   Updated: 2022/06/13 23:53:00 by ekarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

void	ft_putnbr(int num)
{
	int	d;

	d = 0;
	if (num > 9)
		ft_putnbr(num / 10);
	d = num % 10 + 48;
	write(1, &d, 1);
}

int	ft_atoi(char *str)
{
	int	num;

	num = 0;
	while (*str != 0)
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num);
}
