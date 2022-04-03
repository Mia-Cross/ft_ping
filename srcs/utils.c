/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarabe <lemarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:35:06 by lemarabe          #+#    #+#             */
/*   Updated: 2022/04/03 22:39:01 by lemarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ping.h"

// char *uint32_to_dotted_notation_ip(uint32_t ip_int)
// {
// 	char *ip_text;

// 	ip_text = malloc(sizeof(char) * 16);
	
// }

void print_struct_addrinfo(t_addrinfo *a, int print_list)
{
	while (a != NULL)
    {
        printf("PRETTY PRINT FOR STRUCT\n\
            ai_flags = %d\n\
            ai_family =  %d\n\
            ai_socktype = %d\n\
            ai_protocol =  %d\n\
            ai_addrlen =  %d\n\
            ai_canonname = %s\n\
            ai_next = %p\n\
            ai_addr.[...] = %s\n", a->ai_flags, a->ai_family, a->ai_socktype,
			a->ai_protocol, a->ai_addrlen,  a->ai_canonname, a->ai_next,
			a->ai_addr->sa_data);
		a = a->ai_next;
		if (!print_list)
			return;
    }
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