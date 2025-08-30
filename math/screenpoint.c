/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenpoint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 16:25:57 by jisokim2          #+#    #+#             */
/*   Updated: 2025/08/30 16:26:38 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathheader.h"

/*
    X * Y = pixelcounts on screen
*/
t_screenpoint	make_screen(int in_x, int in_y)
{
	t_screenpoint	screen;

	screen.x = in_x;
	screen.y = in_y;
	screen.aspect_ratio = (float)screen.x / (float)screen.y;
	return (screen);
}

float	get_screen_aspect_ratio(t_screenpoint *screen)
{
	return (screen->aspect_ratio);
}
