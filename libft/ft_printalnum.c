/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printalnum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarke <cclarke@student.42prague.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:09:54 by cclarke           #+#    #+#             */
/*   Updated: 2025/12/18 17:13:01 by cclarke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_printalnum(char ch, int c, int *i)
{
	int		r;
	char	printch;
	char	*printstr;

	printch = (char)c;
	if (ch == 'd' || ch == 'i')
	{
		printstr = ft_itoa(c);
		if (!printstr)
			return (0);
		r = ft_strlen(printstr);
		write(1, printstr, r);
		free(printstr);
	}
	else
	{
		write(1, &printch, 1);
		r = 1;
	}
	(*i)++;
	return (r);
}
