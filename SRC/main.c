/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 11:30:02 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/01/04 15:23:34 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_format(char *buff)
{
	int		i;
	int		offset;

	offset = -1;
	i = 0;
	while (buff[i])
	{
		if ((i + 1) % 21 == 0 && buff[i] != '\n')
			return (-1);
		else if ((i - offset) % 5 == 0 && buff[i] != '\n')
			return (-1);
		else if (buff[i] != '#' && buff[i] != '.' && (i + 1) % 21 != 0
		&& (i - offset) % 5 != 0)
			return (-1);
		if ((i + 1) % 21 == 0)
			offset++;
		i++;
	}
	if ((i + 1) % 21 != 0)
		return (-1);
	return (offset + 2);
}

void	error_and_exit(void)
{
	ft_putstr("error\n");
	exit(EXIT_SUCCESS);
}

int	main(int ac, char **argv)
{
	int			fd;
	int			map_count;
	int			ret;
	char		buff[BUFF_SIZE];

	if (ac == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			error_and_exit();
		ret = read(fd, buff, BUFF_SIZE);
		buff[ret] = '\0';
		if ((map_count = check_format(buff)) == -1 || map_count > 26)
			error_and_exit();
		
		close(fd);
		if (setup_solver(buff, map_count) == -1)
			error_and_exit();
	}
	else
		ft_putstr("usage: fillit map_file\n");
	exit(EXIT_SUCCESS);
}
