/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:36:46 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/23 16:46:08 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

short int	pf_fd_convert_int(int fd, va_list args)
{
	int		argi;
	int		len;
	char	*res;

	argi = va_arg(args, int);
	res = ft_itoa(argi);
	len = ft_strlen(res);
	ft_putstr_fd(res, fd);
	free(res);
	return (len);
}

int	pf_fd_convert_str(int fd, const char *s, va_list args)
{
	char	*argstr;
	size_t	i;

	argstr = va_arg(args, char *);
	if (argstr == NULL)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	else if (!argstr)
		return (0);
	i = 0;
	while (argstr[i])
	{
		write(fd, &argstr[i], 1);
		i++;
	}
	s++;
	return (i);
}

short int	pf_fd_convert_ui(int fd, const char *s, va_list args)
{
	unsigned int	argu;
	short int		len;

	argu = va_arg(args, unsigned int);
	ft_putlong_fd((long long)argu, fd);
	len = 1;
	while (argu >= 10)
	{
		len++;
		argu /= 10;
	}
	s++;
	return (len);
}

short int	pf_fd_convert_hex(int fd, const char *s, va_list args, char c)
{
	unsigned long	argl;
	char			*res;
	short int		len;
	char			*hex;

	argl = va_arg(args, unsigned long);
	res = NULL;
	if (c == 'x')
		hex = ft_strdup("0123456789abcdef");
	else
		hex = ft_strdup("0123456789ABCDEF");
	res = ft_intbase(argl, hex, 16);
	len = ft_strlen(res);
	ft_putstr_fd(res, fd);
	free(hex);
	free(res);
	s++;
	return (len);
}

short int	pf_fd_convert_ptr(int fd, const char *s, va_list args)
{
	long long	argp;
	char		*res;
	short int	len;

	argp = va_arg(args, long long);
	if (!argp)
	{
		write(fd, "(nil)", 5);
		return (5);
	}
	res = ft_longbase(argp, "0123456789abcdef", 16);
	write(fd, "0x", 2);
	ft_putstr_fd(res, fd);
	len = ft_strlen(res) + 2;
	free(res);
	s++;
	return (len);
}
