/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 13:51:05 by nvan-der      #+#    #+#                 */
/*   Updated: 2021/05/07 17:00:27 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	size;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1);
	size += ft_strlen(s2);
	size++;
	result = malloc(sizeof(char) * size);
	if (result == NULL)
	{
		free(s1);
		return (NULL);
	}
	ft_strlcpy(result, s1, size);
	ft_strlcat(result, s2, size);
	free(s1);
	return (result);
}
