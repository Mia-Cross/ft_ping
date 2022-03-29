/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 22:40:28 by lemarabe          #+#    #+#             */
/*   Updated: 2022/03/29 22:59:18 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int g_ctrl_c = 0;

void sig_int_handler(int signo)
{
    (void)signo;
    g_ctrl_c = 1;
}

int do_the_ping(unsigned int *p_sent)
{
    // open connexion to ip
        // if fail -> exit
    // send packet
    *p_sent += 1;
    // recv message
        // if fail, output fail and return 1
        // if success, output success and return 0
    sleep(1);
    return 0;
}

int main(int ac, char **av)
{
    char *address;
    unsigned int seq_count = 1;
    unsigned int p_received = 0;
    unsigned int p_sent = 0;

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
    while (!g_ctrl_c)
    {
        if (do_the_ping(&p_sent) == 0)
            p_received++;
        printf("%d bytes from %s: icmp_seq=%d ttl=%d time=%.3f ms\n", 64, "IP/SERVER.GOES.HERE", seq_count++, 999, 999.999);
    }
    printf("\n--- %s ping statistics ---\n", address);
    printf("%d packets transmitted, %d received, %d%% packet loss, time %dms\n", p_sent, p_received, 100 - (p_received * 100 / p_sent), 9999);
    printf("rtt min/avg/max/mdev = %.3f/%.3f/%.3f/%.3f ms\n", 9.9, 9.9, 9.9, 9.9);
    exit(0);
}