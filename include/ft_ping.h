/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 23:52:39 by lemarabe          #+#    #+#             */
/*   Updated: 2022/03/30 00:34:24 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <strings.h>

typedef struct timeval	t_timeval;

typedef struct s_ping
{
    unsigned int seq_count;
    unsigned int p_received;
    unsigned int p_sent;
    float total_time;
}                       t_ping;