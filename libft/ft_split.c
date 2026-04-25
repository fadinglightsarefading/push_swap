/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarke <cclarke@student.42prague.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:16:10 by cclarke           #+#    #+#             */
/*   Updated: 2025/12/04 17:05:09 by cclarke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*ft_replace_delimiter(char *str, char ch, int *cnt)
{
	int	i;

	i = 0;
	*cnt = 0;
	while (str[i])
	{
		while (str[i] == ch)
			i++;
		if (str[i] != ch && str[i] != '\0')
			(*cnt)++;
		while (str[i] != ch && str[i] != '\0')
			i++;
		if (str[i] == ch)
			str[i++] = '\0';
	}
	return (str);
}

static char	**ft_construct(char **split, char *str, char ch, int *cnt)
{
	int	i;

	i = 0;
	while ((*cnt)--)
	{
		while (*str == ch)
			str++;
		split[i++] = ft_strdup(str);
		if (!(split[i - 1]))
			return (NULL);
		while (*str)
			str++;
		str++;
	}
	split[i] = NULL;
	return (split);
}

char	**ft_split(const char *s, char c)
{
	int		count;
	char	*string;
	char	**final;

	string = ft_strdup(s);
	if (!string)
		return (NULL);
	string = ft_replace_delimiter(string, c, &count);
	final = malloc((count + 1) * sizeof(char *));
	if (!final)
		return (NULL);
	final = ft_construct(final, string, c, &count);
	if (!final)
		return (NULL);
	free(string);
	return (final);
}
