/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarke <cclarke@student.42prague.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:51:33 by cclarke           #+#    #+#             */
/*   Updated: 2025/12/04 16:50:26 by cclarke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned int	i;
	void			*a;

	a = malloc(nmemb * size);
	if (a == NULL || (nmemb >= (SIZE_MAX - 5) && nmemb <= SIZE_MAX
			&& size >= (SIZE_MAX - 5) && size <= SIZE_MAX))
		return (NULL);
	i = 0;
	while (i < nmemb * size)
		((unsigned char *)a)[i++] = 0;
	return (a);
}
