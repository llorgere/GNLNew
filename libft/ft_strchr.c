/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 14:18:28 by phanna            #+#    #+#             */
/*   Updated: 2018/04/08 18:54:00 by llorgere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	tmp;
	char	*tmp2;

	i = 0;
	tmp = (char)c;
	tmp2 = (char *)s;
	while (tmp2[i] && tmp2[i] != tmp)
		++i;
	if (tmp2[i] == tmp)
		return (tmp2 + i);
	return (0);
}
