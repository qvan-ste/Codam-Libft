/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 17:01:33 by qvan-ste      #+#    #+#                 */
/*   Updated: 2023/11/05 15:17:21 by quincy        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*char_dest;
	const char	*char_src;

	if (!dest && !src)
		return (0);
	char_dest = (char *)dest;
	char_src = (const char *)src;
	while (n)
	{
		char_dest[n - 1] = char_src[n - 1];
		n--;
	}
	return (dest);
}
