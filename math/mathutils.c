/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 16:28:07 by jisokim2          #+#    #+#             */
/*   Updated: 2025/08/30 16:29:53 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #define TWOPI (2.f * PI)
#define PI 3.14159265358979323846f
#define HALFPI 1.57079632679f
#define INVPI   0.31830988618f

//degree ---> radian.
float	deg2rad(float indegree)
{
	return (indegree * PI / 180.f);
}

/*
void    get_sin_cos(float* outcos, float* outsin, float indegree)
{
    if (indegree == 0.f)
    {
        *outsin = 0.f;
        *outcos = 1.f;
    }
    else if (indegree == 90.f)
    {
        *outcos = 0.f;
        *outsin = 1.f;
    }
    else if (indegree == 180.f)
    {
        *outsin = 0.f;
	    *outcos = -1.f;
    }
    else if (indegree == 270.f)
    {
        *outsin = -1.f;
        *outcos = 0.f;
    }
    else
    {
        get_sin_cos_rad(outcos, outsin, deg2rad(indegree));
    }
}
 */
