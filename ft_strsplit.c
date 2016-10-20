/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 15:09:45 by ydang             #+#    #+#             */
/*   Updated: 2016/10/12 15:09:47 by ydang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	**alloc_wds(const char *s, char c)
{
	char	**wds;
	size_t	len;

	len = 0;
	while (*s)
	{
		while (*s == c && *s)
			s += 1;
		if (*s)
			len++;
		while (*s != c && *s)
			s += 1;
	}
	wds = (char**)malloc(sizeof(char*) * (len + 1));
	if (wds)
		wds[len] = NULL;
	return (wds);
}

char		**ft_strsplit(const char *s, char c)
{
	char	**wds;
	size_t	index;
	size_t	wdi;
	size_t	chi;

	wdi = 0;
	index = 0;
	if (!s || !(wds = alloc_wds(s, c)))
		return (NULL);
	while (s[index])
	{
		chi = 0;
		while (s[index] == c && s[index])
			index++;
		while (s[index + chi] != c && s[index + chi])
			chi++;
		if (chi)
			wds[wdi] = ft_strsub(s, index, chi);
		wdi++;
		index += chi;
	}
	return (wds);
}
