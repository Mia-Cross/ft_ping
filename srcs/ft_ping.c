/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 22:40:28 by lemarabe          #+#    #+#             */
/*   Updated: 2022/04/03 23:06:08 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ping.h"

int g_ctrl_c = 0;

void sig_int_handler(int signo)
{
    (void)signo;
    g_ctrl_c = 1;
}

int do_the_ping(t_ping *ping)
{
    t_timeval start;
    float ping_time;

    // send packet
    ping->p_sent++;
    if (gettimeofday(&start, NULL) != 0)
        exit(1);
    sleep(1);
    // recv message
        // if success, output success and return 0
    ping_time = get_time_since_start(&start);
    printf("%d bytes from %s: icmp_seq=%d ttl=%d time=%.3f ms\n", 64, "IP/SERVER.GOES.HERE", ++ping->seq_count, 999, ping_time);
    ping->total_time += ping_time;
    return 0;
        // if fail, output fail and return 1
}

t_addrinfo *do_the_dns_resolution(char *target)
{
    t_addrinfo *address;
    t_addrinfo hints;
    uint32_t    ip;
    char *ip_text;
    
    // address = NULL;
    ft_bzero(&hints, sizeof(t_addrinfo));
    hints.ai_flags = AI_CANONNAME;//, AI_CANONIDN;
    if (getaddrinfo(target, NULL, &hints, &address) != 0) 
    {
        perror(strerror(errno));
        exit(1);
    }
    print_struct_addrinfo(address, 0);
    // open connexion to ip
        // if fail -> exit
    // if (atoi(ip_text) == 0)
    //     ip_text = "127.0.0.1";
    ip_text = "";
    // ip_text = address->ai_addr;
    if (inet_pton(AF_INET, ip_text, (void*)&ip) < 1)
    {
        printf("failed to convert address (pton)\n");
        exit(1);
    }
    printf("PING %s (%s) %d(%d) bytes of data.\n", address->ai_canonname, ip_text, 56, 84);
    return address;
}

int main(int ac, char **av)
{
    // char *address;
    t_ping      ping;
    t_addrinfo  *address;

    if (ac < 2)
    {
        printf("ft_ping: usage error: Destination address required\n");
        exit(1);
    }
    signal(SIGINT, &sig_int_handler);
    // handle flags if necessary
    address = do_the_dns_resolution(av[ac - 1]);
    ft_bzero(&ping, sizeof(t_ping));
    while (!g_ctrl_c)
        do_the_ping(&ping);
    printf("\n--- %s ping statistics ---\n", address->ai_canonname);
    printf("%d packets transmitted, %d received, %d%% packet loss, time %fms\n", ping.p_sent, ping.p_received, 100 - (ping.p_received * 100 / ping.p_sent), ping.total_time);
    printf("rtt min/avg/max/mdev = %.3f/%.3f/%.3f/%.3f ms\n", 9.9, 9.9, 9.9, 9.9);
    exit(0);
}