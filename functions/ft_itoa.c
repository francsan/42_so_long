/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francsan <francsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:14:17 by francsan          #+#    #+#             */
/*   Updated: 2023/01/31 16:21:44 by francsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*rev_num(char *num)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	if (num[i] == '-')
		i++;
	j = ft_strlen(num) - 1;
	while (i < j)
	{
		c = num[i];
		num[i] = num[j];
		num[j] = c;
		i++;
		j--;
	}
	return (num);
}

void	put_num(int n, char *num)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		num[i++] = '-';
		num[i++] = '8';
		n = 214748364;
	}
	if (n < 0)
	{
		num[i++] = '-';
		n *= -1;
	}
	if (n == 0)
	{
		num[i++] = '0';
	}
	while (n > 0)
	{
		num[i++] = n % 10 + 48;
		n /= 10;
	}
	num[i] = '\0';
}

char	*ft_itoa(int n)
{
	char	*num;
	int		nbr;
	int		mem_size;

	if (n == 0)
		return (ft_strdup("0"));
	nbr = n;
	mem_size = 0;
	while (nbr)
	{
		if (nbr < 0)
		{
			nbr *= -1;
			mem_size++;
		}
		nbr /= 10;
		mem_size++;
	}
	num = malloc((mem_size + 1) * sizeof(char));
	if (!num)
		return (NULL);
	put_num(n, num);
	return (rev_num(num));
}
