/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:38:16 by mbecker           #+#    #+#             */
/*   Updated: 2023/11/16 15:22:56 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*s;
	size_t	dlen;
	size_t	res;
	size_t	slen;
	size_t	i;

	s = (char *)src;
	dlen = ft_strlen(dst);
	slen = ft_strlen(s);
	res = 0;
	i = 0;
	if (size > dlen)
		res = slen + dlen;
	else
		res = slen + size;
	while (s[i] && (dlen + 1) < size)
	{
		dst[dlen] = s[i];
		dlen++;
		i++;
	}
	dst[dlen] = '\0';
	return (res);
}
