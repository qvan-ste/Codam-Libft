/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 14:09:47 by qvan-ste      #+#    #+#                 */
/*   Updated: 2023/11/03 17:49:03 by quincy        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*empty_string(void)
{
	char	*sub_s;

	sub_s = malloc(sizeof(char));
	if (!sub_s)
		return (0);
	*sub_s = 0;
	return (sub_s);
}

static int	is_in_arr(const char c, char const *arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (arr[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*trimmed;

	start = 0;
	end = ft_strlen(s1) - 1;
	i = 0;
	while (is_in_arr(s1[start], set))
		start++;
	if (start == (int) ft_strlen(s1))
		return (empty_string());
	while (is_in_arr(s1[end], set))
		end--;
	trimmed = malloc(end * sizeof(const char) - start * sizeof(const char) + 2);
	if (!trimmed)
		return (0);
	while (start <= end)
	{
		trimmed[i] = s1[start];
		start++;
		i++;
	}
	trimmed[i] = '\0';
	return (trimmed);
}
