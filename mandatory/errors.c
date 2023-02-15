/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francsan <francsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:19:49 by francisco         #+#    #+#             */
/*   Updated: 2023/02/15 19:22:19 by francsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error_msg_free(t_game **game, char *error)
{
	ft_strarr_free((*game)->grid);
	free(*game);
	write(2, error, ft_strlen(error));
	exit(EXIT_SUCCESS);
}

void	error_msg(char *error)
{
	write(2, error, ft_strlen(error));
	exit(EXIT_SUCCESS);
}
