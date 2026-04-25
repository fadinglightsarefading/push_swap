/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarke <cclarke@student.42prague.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 17:59:57 by cclarke           #+#    #+#             */
/*   Updated: 2025/12/18 17:40:21 by cclarke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_printunsdec(unsigned int u)
{
	int		len;
	char	*printstr;

	printstr = ft_unsigned_itoa(u);
	if (!printstr)
		return (0);
	len = ft_strlen(printstr);
	write(1, printstr, len);
	free(printstr);
	return (len);
}

static void	ft_puthex(unsigned int n, char *hex, int *len)
{
	if (n >= 16)
		ft_puthex((n / 16), hex, len);
	write(1, &hex[n % 16], 1);
	(*len)++;
}

int	ft_printunsigned(char x, unsigned int n, int *i)
{
	int		len;
	char	*hexlower;
	char	*hexupper;

	len = 0;
	hexlower = "0123456789abcdef";
	hexupper = "0123456789ABCDEF";
	if (x == 'u')
		len = ft_printunsdec(n);
	else if (x == 'x')
		ft_puthex(n, hexlower, &len);
	else
		ft_puthex(n, hexupper, &len);
	(*i)++;
	return (len);
}
