/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarke <cclarke@student.42prague.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:17:06 by cclarke           #+#    #+#             */
/*   Updated: 2025/11/29 17:13:42 by cclarke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_memcmp(const void *s1, const void *s2, unsigned int n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;

	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	while (n--)
	{
		if (*str1 != *str2)
			return ((int)((unsigned char)*str1 - (unsigned char)*str2));
		else
		{
			str1++;
			str2++;
		}
	}
	return (0);
}
