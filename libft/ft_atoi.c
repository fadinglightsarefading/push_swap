/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarke <cclarke@student.42prague.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:07:27 by cclarke           #+#    #+#             */
/*   Updated: 2025/12/04 16:48:04 by cclarke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static const char	*ft_beginning(const char *nptr, int *pluses)
{
	*pluses = 0;
	while (*nptr == ' ' || *nptr == '+' || (*nptr >= 9 && *nptr <= 13))
	{
		if (*nptr >= 9 && *nptr <= 13 && *pluses)
			return (0);
		if (*nptr == '+')
			(*pluses)++;
		nptr++;
	}
	return (nptr);
}

int	ft_atoi(const char *nptr)
{
	int		negate;
	int		pluses;
	long	final;

	negate = 1;
	final = 0;
	nptr = ft_beginning(nptr, &pluses);
	if (!nptr)
		return (0);
	if (*nptr == '-')
	{
		if (pluses > 0)
			return (0);
		negate = -negate;
		nptr++;
	}
	if (pluses < 2)
		while (*nptr >= '0' && *nptr <= '9')
			final = final * 10 + (*nptr++ - 48);
	return ((int)(final * negate));
}
