/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_graphic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 16:59:17 by echiles           #+#    #+#             */
/*   Updated: 2021/02/02 16:59:18 by echiles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub.h"

void	ft_cleaner(t_data *img)
{
	if (img->qu->map)
		ft_cleaner_mass(img->qu->map);
	if (img->qu)
	{
		free(img->qu->sprite);
		free(img->qu);
	}
	if (img->qu->save_flag == 0)
		mlx_destroy_window(img->mlx, img->mlx_win);
	free(img->mlx);
	if (img->all_wall_dist)
		free(img->all_wall_dist);
	free(img);
	exit(1);
}

int		ft_key_close(t_data *img)
{
	ft_cleaner(img);
	return (0);
}
