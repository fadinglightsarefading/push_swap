/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarke <cclarke@student.42prague.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 17:56:04 by cclarke           #+#    #+#             */
/*   Updated: 2025/12/18 17:20:45 by cclarke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_determine_type(const char *s, int *i, va_list ap)
{
	int	r;

	r = 0;
	while (s[++(*i)])
	{
		if (s[*i] == '%' && s[(*i) + 1] == '%')
			r += ft_printpercent(i);
		else if (s[*i] == '%' && (s[(*i) + 1] == 'd' || s[(*i) + 1] == 'c'
				|| s[(*i) + 1] == 'i'))
			r += ft_printalnum(s[(*i) + 1], va_arg(ap, int), i);
		else if (s[*i] == '%' && s[(*i) + 1] == 's')
			r += ft_printstr(va_arg(ap, char *), i);
		else if (s[*i] == '%' && s[(*i) + 1] == 'p')
			r += ft_printhexaddr((unsigned long int)va_arg(ap, void *), i);
		else if (s[*i] == '%' && (s[(*i) + 1] == 'u' || s[(*i) + 1] == 'x'
				|| s[(*i) + 1] == 'X'))
			r += ft_printunsigned(s[(*i) + 1], va_arg(ap, unsigned int), i);
		else
			r += ft_printchar(s[*i]);
	}
	return (r);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;
	int		r;

	va_start(ap, s);
	i = -1;
	r = ft_determine_type(s, &i, ap);
	va_end(ap);
	return (r);
}
