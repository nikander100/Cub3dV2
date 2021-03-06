/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 10:29:29 by nvan-der      #+#    #+#                 */
/*   Updated: 2021/03/22 14:15:18 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	front;
	size_t	back;

	if (s1 == NULL || set == NULL)
		return (NULL);
	front = 0;
	back = ft_strlen(s1);
	while (front < back && ft_strchr(set, s1[front]))
		front++;
	if (front == back)
		return (ft_strdup(""));
	while (ft_strchr(set, s1[back - 1]))
		back--;
	result = ft_substr(s1, front, (back - front));
	if (result == NULL)
		return (NULL);
	return (result);
}
