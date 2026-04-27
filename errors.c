/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarke <cclarke@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 13:33:47 by cclarke           #+#    #+#             */
/*   Updated: 2026/04/27 17:05:47 by cclarke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	empty_string(char *argument)
{
	if (argument[0] == '\0' || (ft_strlen(argument) == 1
			&& (argument[0] == '-' || argument[0] == '+')))
		return (1);
	return (0);
}

int	input_errors(int argc, char *argv[])
{
	int	i;
	int	arg_num;

	if (argc < 2)
		return (0);
	arg_num = 0;
	while (++arg_num < argc)
	{
		if (empty_string(argv[arg_num]))
			return (1);
		i = 0;
		while (argv[arg_num][i])
		{
			if (!ft_isdigit(argv[arg_num][i]) && argv[arg_num][i] != ' '
				&& argv[arg_num][i] != '-' && argv[arg_num][i] != '+')
				return (1);
			i++;
		}
	}
	return (0);
}

int	duplicates(int *input, int len)
{
	int	i;
	int	j;

	if (!input)
		return (1);
	i = -1;
	while (++i < len)
	{
		j = -1;
		while (++j < len)
		{
			if (i == j && i == (len - 1))
				return (0);
			else if (i == j)
				j++;
			if (input[i] == input[j])
				return (1);
		}
	}
	return (0);
}

int	invalid_in_protostack(char **protostack)
{
	int	i;
	int	j;

	i = 0;
	while (protostack[i])
	{
		j = 0;
		if (protostack[i][j] == '+' || protostack[i][j] == '-')
			j++;
		while (protostack[i][j])
		{
			if (protostack[i][j] == '+' || protostack[i][j] == '-')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
