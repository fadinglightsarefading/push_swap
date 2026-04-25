/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarke <cclarke@student.42prague.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 18:23:33 by cclarke           #+#    #+#             */
/*   Updated: 2025/12/04 17:26:11 by cclarke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	int				allocamt;
	char			*sub;

	if (start > (ft_strlen(s) + 1))
	{
		allocamt = 1;
		start = ft_strlen(s);
	}
	else if (len > ft_strlen(s) - start)
		allocamt = ft_strlen(s) - start + 1;
	else
		allocamt = ft_strlen(s) - (ft_strlen(s) - len) + 1;
	sub = malloc(allocamt * sizeof(char));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (i < (unsigned int)allocamt && i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	return (sub);
}
