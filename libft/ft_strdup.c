/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llorgere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 18:00:27 by llorgere          #+#    #+#             */
/*   Updated: 2018/04/08 19:05:51 by llorgere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	//int		j;
	char	*moc;

	i = 0;
	//j = 0;
	while (s[i] != '\0')
		i++;
	moc = (char*)malloc(sizeof(*moc) * (i + 1));
	if (!moc)
		return (NULL);
	//while (j < i)
	i = 0;
	while (s[i] != '\0')
	{
		moc[i] = s[i];
		i++;
	}
	moc[i] = '\0';
	return (moc);
}
