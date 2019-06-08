# Print Memory
The function takes (const void *addr, size_t size), and displays the memory as in the example.

The function prototype:

	void	print_memory(const void *addr, size_t size);

Example:

	$> cat main.c

	void	print_memory(const void *addr, size_t size);

	int	main(void)
	{
		int	tab[10] = {0, 23, 150, 255,
			12, 16,  42, 103};
	
		print_memory(tab, sizeof(tab));
		return (0);
	}

$> gcc -Wall -Wall -Werror main.c print_memory.c && ./a.out | cat -e

	0000 0000 1700 0000 9600 0000 ff00 0000 ................$
	0c00 0000 1000 0000 2a00 0000 6700 0000 ........*...g...$
	0000 0000 0000 0000                     ........$

