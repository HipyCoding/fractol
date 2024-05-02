/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 06:51:04 by candrese          #+#    #+#             */
/*   Updated: 2024/04/30 17:52:29 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	post_comma(char *string)
{
	double	nb;
	double	factor;

	factor = 0.1;
	nb = 0;
	while (*string >= '0' && *string <= '9')
	{
		nb += (*string - '0') * factor;
		factor /= 10;
		string++;
	}
	return (nb);
}

double	atod(char *str)
{
	long	pre_comma;
	int		sign;

	pre_comma = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		++str;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
		{
			sign *= -1;
			str++;
		}
	}
	while ((*str >= '0' && *str <= '9') && *str && *str != '.')
	{
		pre_comma = pre_comma * 10 + (*str - '0');
		str++;
	}
	if (*str == '.')
		++str;
	return ((pre_comma + post_comma(str)) * sign);
}

double	absolute(double nb)
{
	if (nb < 0)
		return (nb * (-1));
	return (nb);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)

{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i] && i < n - 1)
		i++;
	if (n == 0)
		return (0);
	return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
}

void	putstr_fd(char *s, int fd)
{
	if (NULL == s || fd < 0)
		return ;
	if (*s != '\0')
	{
		write(fd, s, 1);
		putstr_fd(s + 1, fd);
	}
}
