#include "fillit.h"

void	binary_printer(uint64_t tab, int size)
{
	char str[size * 4 + 1];
	int	i;

	i = size * 4;
	str[i--] = '\0';
	while (tab)
	{
		str[i--] = tab % 2 + '0';
		tab /= 2;
	}
	while (i >= 0)
		str[i--] = '0';
	i = 0;
	while (str[i])
	{
		ft_putchar(str[i++]);
		if (i % size == 0)
			ft_putchar('\n');
	}
	ft_putchar('\n');
}
/*
int	print_binary(uint64_t *tab, int map_count, int size)
{
	int i;

//	*((uint64_t *)tab) |= 140740709597184;
	i = 0;
	while (i < map_count)
	{
		binary_printer(tab[i++], size);
	}
	return (0);
}*/
