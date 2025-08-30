/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 17:30:48 by jisokim2          #+#    #+#             */
/*   Updated: 2025/08/30 17:40:50 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathheader.h"

t_vec3	vec3_plus_vec3(t_vec3 vec1, t_vec3 vec2)
{
	vec1.x += vec2.x;
	vec1.y += vec2.y;
	vec1.z += vec2.z;
	return (vec1);
}

//vector dot
double	vec3_dot(t_vec3 vec1, t_vec3 vec2)
{
	return (vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z);
}

//vector cross
t_vec3	vec3_cross(t_vec3 vec1, t_vec3 vec2)
{
	t_vec3	new;

	new.x = vec1.y * vec2.z - vec1.z * vec2.y;
	new.y = vec1.z * vec2.x - vec1.x * vec2.z;
	new.z = vec1.x * vec2.y - vec1.y * vec2.x;
	return (new);
}

t_vec3	vec3_negate(t_vec3 v)
{
	t_vec3	negated;

	negated.x = -v.x;
	negated.y = -v.y;
	negated.z = -v.z;
	return (negated);
}

//get unit vector
t_vec3	vec3_normalized(t_vec3 vec3)
{
	double	len;

	len = vec3_length(vec3);
	if (len == 0.0)
	{
		printf("Error Zero Vector can't be normalized! vec3");
		printf("x : %f, y : %f, z : %f\n", vec3.x, vec3.y, vec3.z);
		exit(1);
	}
	vec3.x = vec3.x / len;
	vec3.y = vec3.y / len;
	vec3.z = vec3.z / len;
	return (vec3);
}
