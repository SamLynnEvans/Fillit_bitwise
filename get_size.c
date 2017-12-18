/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 22:12:53 by slynn-ev          #+#    #+#             */
/*   Updated: 2017/12/14 22:13:14 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	get_size(int map_count)
{
	int num;
	int minimum_area;

	minimum_area = map_count * 4;
	num = 0;
	while (1)
	{
		if (num * num >= minimum_area)
			break ;
		num++;
	}
	return (num);
}
