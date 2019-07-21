/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 13:59:27 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/21 13:59:27 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/toolbox.h"

void	ft_print_err(int argc)
{
	if (argc > 2)
		ft_putendl("too many arguments.\nusage: ./fdf [map] or ./fdf \"help\"");
	if (argc < 2)
		ft_putendl("none map found.\nusage: ./fdf [map] or ./fdf \"help\"");
	system("leaks fdf");
	exit(EXIT_FAILURE);
}

void	ft_help(void)
{
	ft_putstr("\t./fdf [map] -> ");
	ft_putendl("Map exemple can be found on Map directory\n\
	\t\t\t**INPUT**\n\
	-Press 'q' and 'e' to add and substract relief.\n\
	-Press '+' and '-' to zoom in and out.\n\
	-Press 'w' 'a' 's' 'd' arrows to move the image.\n\
	-Press 'esc' to exit the program.\n\
	-Press 'c' to reset all the changes.");
	system("leaks fdf");
	exit(EXIT_SUCCESS);
}
