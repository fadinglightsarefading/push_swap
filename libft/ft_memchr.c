/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarke <cclarke@student.42prague.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:01:13 by cclarke           #+#    #+#             */
/*   Updated: 2025/11/29 17:12:39 by cclarke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int		i;
	const unsigned char	*str;

	str = (const unsigned char *)s;
	i = 0;
	while (*str++ != (char)c && i < n)
		i++;
	if (i == n)
		return ((void *)0);
	else
		return ((void *)--str);
}
