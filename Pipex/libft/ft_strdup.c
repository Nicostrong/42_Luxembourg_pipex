/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:48:15 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/01/27 10:09:50 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * <cat>str</cat>
 *
 * <summary>
 *	char	*ft_strdup(const char *s)
 *</summary>
 *
 * <description>
 *	ft_strdup duplicate the string pointed by s to a new pointer.
 * </description>
 *
 * <param type="const char *" name="s">string to duplicate</param>
 *
 * <return>
 *	a new string where copied on memory area allocated with malloc.
 * </return>
 *
 */
char	*ft_strdup(const char *s)
{
	char	*cpy;
	size_t	len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s) + 1;
	cpy = (char *)ft_calloc(len_s, sizeof(char));
	if (!cpy)
		return (NULL);
	cpy = ft_memcpy(cpy, s, len_s);
	return (cpy);
}
