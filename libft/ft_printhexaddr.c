/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexaddr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarke <cclarke@student.42prague.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:00:28 by cclarke           #+#    #+#             */
/*   Updated: 2025/12/18 17:39:12 by cclarke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

static int	ft_print_nil(unsigned long int vptr, int *i)
{
	if (vptr == 0)
	{
		(*i)++;
		write(1, "(nil)", 5);
		return (1);
	}
	return (0);
}

static int	ft_determine_len(unsigned long int addr)
{
	int	i;

	i = 0;
	while (addr)
	{
		addr /= 16;
		i++;
	}
	return (i);
}

int	ft_printhexaddr(unsigned long int vptr, int *i)
{
	int		len;
	int		j;
	char	*hex;
	char	*hex_addr;

	if (ft_print_nil(vptr, i))
		return (5);
	hex = "0123456789abcdef";
	len = ft_determine_len(vptr);
	hex_addr = malloc((len + 1) * sizeof(char));
	j = len;
	hex_addr[j--] = '\0';
	while (vptr)
	{
		hex_addr[j--] = hex[vptr % 16];
		vptr /= 16;
	}
	len = ft_strlen(hex_addr);
	write(1, "0x", 2);
	write(1, hex_addr, len);
	free(hex_addr);
	(*i)++;
	return (len + 2);
}
