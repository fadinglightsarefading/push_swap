/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarke <cclarke@student.42prague.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:52:08 by cclarke           #+#    #+#             */
/*   Updated: 2025/12/18 17:05:13 by cclarke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_printstr(char *s, int *i)
{
	int	r;

	if (!s)
	{
		write(1, "(null)", 6);
		(*i)++;
		return (6);
	}
	r = ft_strlen(s);
	write(1, s, r);
	(*i)++;
	return (r);
}
