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

static void	set_line(char *s)
{
	int	i;

	i = 0;
	while (i < 40)
	{
		if (i == 0 || (i + 1) % 5 != 0)
			s[i] = '0';
		else
			s[i] = ' ';
		i++;
	}
	while (i < 56)
	{
		s[i] = '.';
		i++;
	}
	s[56] = '\n';
}

void		print_memory(const void *addr, size_t size)
{
	char		ret[57];
	unsigned char	*v;
	char		*hex;
	unsigned	i;

	v = (unsigned char*)addr;
	hex = "0123456789abcdef";
	i = 0;
	set_line(ret);
	while (i < 16 && i < size)
	{
		ret[i * 2 + i / 2] = hex[v[i] / 16];
		ret[i * 2 + i / 2 + 1] = hex[v[i] % 16];
		if (v[i] > 31 && v[i] < 127)
			ret[40 + i] = v[i];
		i++;
	}
	write(1, ret, 57);
	if (size > 16)
		print_memory(&(addr[16]), size - 16);
}
