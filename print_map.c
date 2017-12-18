#include "fillit.h"

void	print_row(uint16_t tab, int size)
{
	int	i;
	char str[17];

	i = 16;
	str[i--] = '\0';
	while (tab)
	{
		str[i--] = tab % 2 + '0';
		tab /= 2;
	}
	while (i >= 0)
		str[i--] = '0';
	while (i < size)
	{
		if (i != 0)
		ft_putchar(' ');
		ft_putchar(str[i++]);
	}
}

int	print_map(uint16_t *tab, int size)
{
	int i;

//	*((uint64_t *)tab) |= 140740709597184;
	i = 0;
	while (i < size)
	{
		print_row(tab[i], size);
		ft_putchar('\n');
		i++;
	}
	ft_putchar('\n');
	return (0);
}
/*
int	main()
{
	uint16_t map[5];
	
	map[0] = 0;
	map[1] = 0;
	map[2] = 0;
	map[3] = 0;
	map[4] = 0;
	print_binary(map, 0, 5);
}*/
