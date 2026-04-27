/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarke <cclarke@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 13:34:57 by cclarke           #+#    #+#             */
/*   Updated: 2026/04/27 17:05:04 by cclarke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

char	**section_arguments(char *argv[], char ***protostack)
{
	int			i;
	char		*str1;
	char		*str2;

	str1 = ft_strdup("");
	if (!str1)
		return (NULL);
	i = 0;
	while (argv[++i])
	{
		str2 = ft_strjoin(str1, argv[i]);
		free(str1);
		if (!str2)
			return (NULL);
		if (!argv[i + 1])
			break ;
		str1 = ft_strjoin(str2, " ");
		free(str2);
		if (!str1)
			return (NULL);
	}
	*protostack = ft_split(str2, ' ');
	free(str2);
	return (*protostack);
}

int	check_length(char **protostack)
{
	int	i;

	i = 0;
	while (protostack[i])
	{
		if (ft_strlen_skip_zeroes(protostack[i]) > 11)
			return (1);
		i++;
	}
	return (0);
}

int	init_interm(char **protostack, long *input_numbers_interm, int true_argc)
{
	while (true_argc--)
	{
		input_numbers_interm[true_argc] = ft_atol(protostack[true_argc]);
		if (input_numbers_interm[true_argc] > INT_MAX
			|| input_numbers_interm[true_argc] < INT_MIN)
			return (1);
	}
	return (0);
}

int	*final_set(int arg_count, char ***protostack)
{
	int			*input_numbers;
	long		*input_numbers_interm;

	input_numbers_interm = malloc(arg_count * sizeof(long));
	if (!input_numbers_interm)
		return (NULL);
	if (init_interm(*protostack, input_numbers_interm, arg_count))
	{
		free_protostack(protostack);
		free(input_numbers_interm);
		return (NULL);
	}
	free_protostack(protostack);
	input_numbers = malloc(arg_count * sizeof(int));
	if (!input_numbers)
		return (NULL);
	while (arg_count--)
		input_numbers[arg_count] = (int)input_numbers_interm[arg_count];
	free(input_numbers_interm);
	return (input_numbers);
}

int	*parse_input(int argc, char *argv[], int *arg_count)
{
	int			*input_numbers;
	char		**protostack;

	if (input_errors(argc, argv))
		return (NULL);
	protostack = section_arguments(argv, &protostack);
	if (!protostack)
		return (NULL);
	if (check_length(protostack))
	{
		free_protostack(&protostack);
		return (NULL);
	}
	*arg_count = 0;
	while (protostack[*arg_count])
		(*arg_count)++;
	if (invalid_in_protostack(protostack))
	{
		free_protostack(&protostack);
		return (NULL);
	}
	input_numbers = final_set(*arg_count, &protostack);
	if (duplicates(input_numbers, *arg_count))
		return (NULL);
	return (input_numbers);
}
