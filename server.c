/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 09:55:07 by graja             #+#    #+#             */
/*   Updated: 2021/08/01 13:39:28 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

/* it is rule because compiling with flags that every
 * param of the function must be used in code even though
 * you do not need them. This is why you find the strange
 * OR and num before doing the bit shift */

static
void	handlera(int num, siginfo_t *inf, void *ctxt)
{
	static int	n;
	static char	c;

	if (!c)
		c = 0;
	if (!n)
		n = 1;
	if (num && inf->si_signo == 10 && (ctxt || !ctxt))
		c += 1 << (n - 1);
	n++;
	if (n == 9)
	{
		write(1, &c, 1);
		n = 1;
		c = 0;
	}
	kill(inf->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sgl;
	char				*strpid;

	strpid = ft_itoa(getpid());
	sgl.sa_flags = SA_SIGINFO;
	sgl.sa_sigaction = &handlera;
	sigaction(SIGUSR1, &sgl, NULL);
	sigaction(SIGUSR2, &sgl, NULL);
	write(1, ">>> Server PID is #", 19);
	write(1, strpid, ft_strlen(strpid));
	write(1, " <<<\n", 5);
	free(strpid);
	while (1)
		pause();
}
