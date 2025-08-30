/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 16:30:11 by jisokim2          #+#    #+#             */
/*   Updated: 2025/08/30 16:31:31 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathheader.h"

t_quaternion	init_quaternion(void)
{
	t_quaternion	quaternion;

	quaternion.x = 0.f;
	quaternion.y = 0.f;
	quaternion.z = 0.f;
	quaternion.w = 1.f;
	return (quaternion);
}

t_quaternion	quaternion_constructor(float inx,
	float iny, float inz, float inw)
{
	t_quaternion	quaternion;

	quaternion.x = inx;
	quaternion.y = iny;
	quaternion.z = inz;
	quaternion.w = inw;
	return (quaternion);
}
