/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarke <cclarke@student.42prague.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:20:36 by cclarke           #+#    #+#             */
/*   Updated: 2025/11/29 17:55:07 by cclarke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;

	str = (char *)s--;
	if (c > 127)
		return (str);
	while (*++s)
		if (*s == (char)c)
			str = (char *)s;
	if (*str == (char)c)
		return (str);
	else if (*s == (char)c)
		return ((char *)s);
	else
		return (NULL);
}
