/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarke <cclarke@student.42prague.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:26:11 by cclarke           #+#    #+#             */
/*   Updated: 2025/12/04 17:19:36 by cclarke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_trim_len(const char *str, const char *set)
{
	int	i;
	int	trim_len;

	trim_len = 0;
	while (*str)
	{
		i = 0;
		while (i < (int)ft_strlen(set))
			if (set[i++] == *str)
				trim_len++;
		str++;
	}
	return (trim_len);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		i;
	int		j;
	int		trim_len;
	int		flag;
	char	*s2;

	trim_len = ft_trim_len(s1, set);
	s2 = malloc((ft_strlen(s1) - trim_len + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	i = 0;
	while (*s1)
	{
		j = 0;
		flag = 0;
		while (j < (int)ft_strlen(set))
			if (set[j++] == *s1)
				flag++;
		if (!flag)
			s2[i++] = *s1++;
		else
			s1++;
	}
	s2[i] = '\0';
	return (s2);
}
