/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:23:10 by jonnavar          #+#    #+#             */
/*   Updated: 2023/11/13 09:25:06 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *string, void (*function)(unsigned int, char*))
{
	unsigned int	index;

	if (!string || !function)
		return ;
	index = 0;
	while (string[index])
	{
		(*function)(index, string + index);
		index ++;
	}
}
