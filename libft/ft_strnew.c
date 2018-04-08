/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llorgere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 15:37:13 by llorgere          #+#    #+#             */
/*   Updated: 2018/04/08 14:24:06 by llorgere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*tab;
	size_t	i;

	tab = 0;
	i = 0;
	tab = (char*)malloc(sizeof(char) * ((size + 1)));
	if (tab == 0)
		return (0);
	while (i < size)
	{
		tab[i] = 0;
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
