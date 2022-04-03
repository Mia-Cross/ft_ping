/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 23:52:39 by lemarabe          #+#    #+#             */
/*   Updated: 2022/04/03 22:21:10 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>
#include "../libft/include/libft.h"

typedef struct timeval      t_timeval;
typedef struct addrinfo     t_addrinfo;
typedef struct sockaddr_in  t_sockaddr;
typedef struct s_ping
{
    unsigned int seq_count;
    unsigned int p_received;
    unsigned int p_sent;
    float total_time;
}                       t_ping;

float get_time_since_start(t_timeval *start);
void print_struct_addrinfo(t_addrinfo *a, int print_list);

// struct addrinfo {
//     int              ai_flags;
//     int              ai_family;
//     int              ai_socktype;
//     int              ai_protocol;
//     socklen_t        ai_addrlen;
//     struct sockaddr *ai_addr;
//     char            *ai_canonname;
//     struct addrinfo *ai_next;
// };

// struct sockaddr {
//         ushort  sa_family;
//         char    sa_data[14];
// };

// struct sockaddr_in {
//     sa_family_t    sin_family; /* address family: AF_INET */
//     in_port_t      sin_port;   /* port in network byte order */
//     struct in_addr sin_addr;   /* internet address */
// };

// struct in_addr {
//     uint32_t       s_addr;     /* address in network byte order */
// };