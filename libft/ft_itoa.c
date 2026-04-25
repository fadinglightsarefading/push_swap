/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarke <cclarke@student.42prague.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:17:44 by cclarke           #+#    #+#             */
/*   Updated: 2025/12/10 17:34:45 by cclarke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_determine_len(int n, int neg)
{
	int	len;

	len = 1;
	if (n == 0)
		len++;
	while (n)
	{
		len++;
		n /= 10;
	}
	if (neg == -1)
		len++;
	return (len);
}

static char	*ft_final(int negflag, int nlen, long interm)
{
	char	*final;

	final = malloc(nlen * sizeof(char));
	if (final == NULL)
		return (NULL);
	final[--nlen] = '\0';
	while (--nlen)
	{
		final[nlen] = (char)(interm % 10 + 48);
		interm /= 10;
	}
	if (negflag == -1)
		final[0] = '-';
	else
		final[0] = (char)(interm + 48);
	return (final);
}

char	*ft_itoa(int n)
{
	int		negflag;
	int		nlen;
	long	interm;

	interm = (long)n;
	negflag = 1;
	if (n < 0)
		negflag = -negflag;
	interm *= negflag;
	n *= negflag;
	nlen = ft_determine_len(n, negflag);
	return (ft_final(negflag, nlen, interm));
}
