/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_memory.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/22 16:34:58 by pacovali      #+#    #+#                 */
/*   Updated: 2019/04/22 16:34:58 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putstrn(char *s)
{
	while (s[0])
	{
		write(1, s, 1);
		s++;
	}
	write(1, "\n", 1);
}

static void	setstr(char *s)
{
	int		i;

	i = 0;
	while (i < 40)
	{
		s[i] = ' ';
		i++;
	}
	s[40] = 0;
}

static int	ft_setdot(char *s, unsigned char *c, int i)
{
	if (c[i] > 31 && c[i] < 127)
		s[40 + i % 16] = c[i];
	else
		s[40 + i % 16] = '.';
	s[40 + (i) % 16 + 1] = 0;
	return (0);
}

void		print_memory(const void *addr, size_t size)
{
	char	s[57];
	char	*oct;
	int		i;

	i = -1;
	oct = "0123456789abcdef";
	while (++i < (int)size)
	{
		if (i % 16 == 0)
		{
			if (i / 16 > 0)
				ft_putstrn(s);
			setstr(s);
		}
		s[i % 16 * 2 + (i % 16 / 2)] = oct[((unsigned char*)addr)[i] / 16];
		s[i % 16 * 2 + 1 + (i % 16 / 2)] = oct[((unsigned char*)addr)[i] % 16];
		ft_setdot(s, (unsigned char*)addr, i);
	}
	ft_putstrn(s);
}
