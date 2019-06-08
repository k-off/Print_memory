/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/22 16:34:58 by pacovali      #+#    #+#                 */
/*   Updated: 2019/04/22 16:34:58 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_memory(const void *addr, size_t size);

int		main(void)
{
	int	tab[10] = {0, 23, 150, 255,
		12, 16,  42, 103};
	print_memory(tab, sizeof(tab));
	return (0);
}
