/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 16:13:35 by graja             #+#    #+#             */
/*   Updated: 2021/08/01 13:41:12 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

static
int	ft_sgn(int pid, char c, int n)
{
	if (c & (1 << n))
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	n++;
	return (n);
}

static
void	ft_send_str(int npid, char *str)
{
	static int	i;
	static int	j;
	static char	*ptr;
	static int	p;

	if (str)
	{
		ptr = str;
		p = npid;
		i = 0;
		j = 0;
	}
	if (j == 8)
	{
		j = 0;
		i++;
	}
	if (ptr[i])
		j = ft_sgn(p, ptr[i], j);
	else
		exit(0);
}

/* it is rule because compiling with flags that every
 * param of the function must be used in code even though
 * you do not need them. This why you find the strange
 * OR and num before calling send_str */

static
void	handle(int num, siginfo_t *inf, void *ctxt)
{
	if (num && (ctxt || !ctxt) && inf)
		ft_send_str(0, NULL);
}

int	main(int argc, char **argv)
{
	int					npid;
	struct sigaction	sgl;

	sgl.sa_flags = SA_SIGINFO;
	sgl.sa_sigaction = &handle;
	sigaction(SIGUSR1, &sgl, NULL);
	if (argc < 3)
	{
		write(1, "ERROR: client <PID> <STRING>\n", 29);
		return (0);
	}
	npid = ft_atoi(argv[1]);
	if (npid <= 0 || kill(npid, 0) < 0)
	{
		write(1, "ERROR: invalid PID\n", 19);
		return (0);
	}
	ft_send_str(npid, argv[2]);
	while (1)
		pause();
	return (1);
}
