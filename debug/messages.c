/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:14:47 by tfarkas           #+#    #+#             */
/*   Updated: 2025/07/16 20:06:48 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_tools.h"
#include "../object/objects.h"

void	print_vec3(const t_vec3 * vec3)
{
	if (!vec3)
	{
		printf("%sThe vector point is NULL%s\n", RED, DEFAULT);
		return ;
	}
	printf("The vector has the following values\n"
		"x:\t%f\ny:\t%f\nz:\t%f\n", vec3->x, vec3->y, vec3->z);
}

void	print_color_float(const t_color_float *float_color)
{
	printf("\nThe float color values:\n"
		"red: %f\tgreen: %f\tblue: %f\n",
		float_color->red, float_color->green, float_color->blue);
}

void	print_sphere_infos(const t_sphere *sphere)
{
	printf("\nThe sphere:\ncenter:\n");
	print_vec3(&sphere->center);
	printf("diamater: %f\n", sphere->diameter);
	print_color_float(&sphere->sphere_color);
	if (sphere->obj_fill == SOLID)
		printf("fill type: SOLID\n");
	else
		printf("fill type: SHELL\n");
}

/*
	The print_objs function created to check the object list object types.
	Print out the terminal the object type name.
*/
void	print_objs(t_objs_list *obj)
{
	t_objs_list	*cur;

	cur = obj;
	while (cur)
	{
		if (cur->obj_type == PLANE)
			printf("current object is PLANE\n");
		else if (cur->obj_type == CYLINDER)
			printf("current object is CYLINDER\n");
		else if (cur->obj_type == SPHERE)
		{
			printf("current object is SPHERE\n");
			print_sphere_infos((t_sphere *)(obj->data));
		}
		cur = cur->next;
	}
}

void	print_hit_t(const t_hit *hit)
{
	printf("The hit t_min: %f\tt_max: %f\tt: %f values\n",
		hit->t_min, hit->t_max, hit->t);
}
