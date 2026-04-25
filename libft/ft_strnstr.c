/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarke <cclarke@student.42prague.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:52:18 by cclarke           #+#    #+#             */
/*   Updated: 2025/12/04 17:09:33 by cclarke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*cbig;
	char	*clittle;

	if ((!len || !(len + 1)) && !ft_strlen(little))
		return ((char *)big);
	if (len == 1 && ft_strlen(little) == 1)
		len++;
	if (len)
	{
		while (*big && --len)
		{
			cbig = (char *)big;
			clittle = (char *)little;
			while (*cbig && *clittle && (*cbig == *clittle))
			{
				cbig++;
				clittle++;
			}
			if (!(*clittle))
				return ((char *)big);
			big++;
		}
	}
	return (NULL);
}
