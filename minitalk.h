/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 15:19:41 by graja             #+#    #+#             */
/*   Updated: 2021/08/01 09:54:43 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

size_t	ft_strlen(const char *s);
int		ft_space(char c);
int		ft_atoi(const char *nptr);
int		ft_isdigit(int c);
char	*ft_itoa(int n);

#endif
