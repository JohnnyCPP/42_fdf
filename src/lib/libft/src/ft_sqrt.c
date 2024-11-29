/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:55:21 by jonnavar          #+#    #+#             */
/*   Updated: 2023/10/02 17:56:00 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(const int number)
{
	int	index;
	int	power;
	int	substract;

	if (number < 4)
		return (1);
	index = 2;
	while (index * index < number)
		index ++;
	power = index * index;
	substract = index - 1;
	if (power > number)
	{
		if ((power - number) < (substract * substract + (-number)))
			return (index);
	}
	return (substract);
}
