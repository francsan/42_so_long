/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarr_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francsan <francsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:36:45 by francsan          #+#    #+#             */
/*   Updated: 2023/01/23 23:26:20 by francsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_strarr_free(char **strs)
{
	int	i;

	i = -1;
	while (strs[++i])
		free(strs[i]);
	free(strs);
}
