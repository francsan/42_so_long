/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarr_copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francsan <francsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 23:25:44 by francsan          #+#    #+#             */
/*   Updated: 2023/01/23 23:29:48 by francsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**ft_strarr_copy(char **arr)
{
	char	**dst;
	char	*temp1;
	char	*temp2;
	int		i;

	temp2 = ft_strdup("");
	i = 0;
	while (arr[i])
	{
		temp1 = ft_strjoin(temp2, arr[i]);
		free(temp2);
		temp2 = ft_strjoin(temp1, ":");
		free(temp1);
		i++;
	}
	dst = ft_split(temp2, ':');
	free(temp2);
	return (dst);
}
