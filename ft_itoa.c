/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/16 13:14:08 by qvan-ste      #+#    #+#                 */
/*   Updated: 2023/11/03 17:49:39 by quincy        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(long n)
{
	if (n < 0)
		n = -n;
	if (n > 9)
		return (1 + int_len(n / 10));
	return (1);
}

static char	*int_min(void)
{
	char	*int_min;

	int_min = malloc(12 * sizeof(char));
	if (!int_min)
		return (0);
	ft_memcpy(int_min, "-2147483648", 12);
	return (int_min);
}

static char	*zero(void)
{
	char	*zero;

	zero = malloc(2 * sizeof(char));
	if (!zero)
		return (0);
	ft_memcpy(zero, "0", 2);
	return (zero);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		len;

	if (n == 0)
		return (zero());
	if (n == -2147483648)
		return (int_min());
	len = int_len(n) + (n < 0);
	s = malloc(sizeof(char) * (len + 1));
	if (!s)
		return (0);
	if (n < 0)
	{
		s[0] = '-';
		n = -n;
	}
	s[len] = '\0';
	len--;
	while (n > 0)
	{
		s[len] = n % 10 + 48;
		n /= 10;
		len--;
	}
	return (s);
}
