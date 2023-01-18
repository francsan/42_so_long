/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisco <francisco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:40:42 by francisco         #+#    #+#             */
/*   Updated: 2023/01/13 18:55:51 by francisco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	i;

	len = 0;
	while (src[len] != '\0')
		len++;
	i = 0;
	if (dstsize != 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len);
}

char	*ft_strdup(const char *s1)
{
	char	*dup;

	dup = malloc(ft_strlen(s1) * sizeof(char) + 1);
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s1, (ft_strlen(s1) + 1));
	return (dup);
}
