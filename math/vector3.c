/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 17:09:19 by jisokim2          #+#    #+#             */
/*   Updated: 2025/08/30 17:34:49 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathheader.h"

t_vec3	vec3(double x, double y, double z)
{
	t_vec3	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

void	vec3_set(t_vec3 *vec3, double x, double y, double z)
{
	vec3->x = x;
	vec3->y = y;
	vec3->z = z;
}

//vector len squared
double	vec3_length_squared(t_vec3 vec)
{
	return (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

//vector length (size)
double	vec3_length(t_vec3 vec)
{
	return (sqrt(vec3_length_squared(vec)));
}

t_vec3	vec3_add(t_vec3 vec, double x, double y, double z)
{
	vec.x += x;
	vec.y += y;
	vec.z += z;
	return (vec);
}

// t_vec3	vec3_normalized(t_vec3 vec3)
// {
// 	double len;

// 	len = vec3_length(vec3);
// 	if (len == 0.0)
// 	{
// 		printf("Error Zero Vector can't be normalized!
//			vec3 : %f, %f, %f\n", vec3.x, vec3.y, vec3.z);
// 		exit(1);
// 	}
// 	vec3.x = vec3.x / len;
// 	vec3.y = vec3.y / len;
// 	vec3.z = vec3.z / len;
// 	return (vec3);
// }
// t_vec3  vec3_one()
// {
//     return (t_vec3){1.f, 1.f, 1.f};
// }