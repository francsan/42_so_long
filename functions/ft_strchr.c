/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisco <francisco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:27:24 by francisco         #+#    #+#             */
/*   Updated: 2023/01/13 18:54:59 by francisco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*ft_strchr(const char *s, int c)
{
	int	counter;

	counter = 0;
	while (s[counter] != '\0')
	{
		if (s[counter] == (char)c)
		{
			s += counter;
			return ((char *)s);
		}
		counter++;
	}
	if (s[counter] == (char) c)
	{
		s += counter;
		return ((char *)s);
	}
	return (NULL);
}
