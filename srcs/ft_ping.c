/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 22:40:28 by lemarabe          #+#    #+#             */
/*   Updated: 2022/03/30 00:38:32 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ping.h"

int g_ctrl_c = 0;

void sig_int_handler(int signo)
{
    (void)signo;
    g_ctrl_c = 1;
}

float get_time_since_start(t_timeval *start)
{
	t_timeval	end;
	float		diff;
	float		time_since;

	if (gettimeofday(&end, NULL))
        exit(1);
	diff = end.tv_sec - start->tv_sec;
	time_since = end.tv_usec - start->tv_usec + (1000000 * diff);
	return (time_since / 1000);
}

int do_the_ping(t_ping *ping)
{
    t_timeval start;
    float ping_time;

    // open connexion to ip
        // if fail -> exit
    // send packet
    ping->p_sent++;
    if (gettimeofday(&start, NULL) != 0)
        exit(1);
    sleep(1);
    // recv message
        // if success, output success and return 0
    ping_time = get_time_since_start(&start);
    printf("%d bytes from %s: icmp_seq=%d ttl=%d time=%.3f ms\n", 64, "IP/SERVER.GOES.HERE", ping->seq_count++, 999, ping_time);
    ping->total_time += ping_time;
    return 0;
        // if fail, output fail and return 1
}

int main(int ac, char **av)
{
    char *address;
    t_ping  ping;

    if (ac < 2)
    {
        printf("ft_ping: usage error: Destination address required\n");
        exit(1);
    }
    signal(SIGINT, &sig_int_handler);
    address = av[ac - 1];
    // do the dns resolution here
    printf("PING %s (%s) %d(%d) bytes of data.\n", address, "IP.GOES.HERE", 56, 84);
    // NB: the first key isn't always address : ping images.google.com
    //  outputs -> PING images.l.google.com (...) ...
    bzero(&ping, sizeof(t_ping));
    while (!g_ctrl_c)
        do_the_ping(&ping);
    printf("\n--- %s ping statistics ---\n", address);
    printf("%d packets transmitted, %d received, %d%% packet loss, time %fms\n", ping.p_sent, ping.p_received, 100 - (ping.p_received * 100 / ping.p_sent), ping.total_time);
    printf("rtt min/avg/max/mdev = %.3f/%.3f/%.3f/%.3f ms\n", 9.9, 9.9, 9.9, 9.9);
    exit(0);
}