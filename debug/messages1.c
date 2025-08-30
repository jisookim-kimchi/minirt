/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 18:08:48 by jisokim2          #+#    #+#             */
/*   Updated: 2025/08/30 18:09:43 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_tools.h"
#include "../object/objects.h"

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
		{
			printf("\ncurrent object is PLANE");
			print_plane_infos((t_plane *)(cur->data));
		}
		if (cur->obj_type == CYLINDER)
			printf("current object is CYLINDER\n");
		if (cur->obj_type == SPHERE)
		{
			printf("\ncurrent object is SPHERE\n");
			print_sphere_infos((t_sphere *)(cur->data));
		}
		printf("cur addr : %p\n", cur);
		cur = cur->next;
	}
}

void	print_hit_t(const t_hit *hit)
{
	printf("The hit t_min: %f\tt_max: %f\tt: %f values\n",
		hit->t_min, hit->t_max, hit->t);
}

void	pointer_address_message(void *ptr)
{
	if (ptr == NULL)
		printf("%sThe pointer: NULL%s\n", RED, DEFAULT);
	else
		printf("%sThe pointer address: %p%s\n", YELLOW, ptr, DEFAULT);
}

void	object_adress(t_objs_list *obj)
{
	if (obj == NULL)
		printf("%sThe object: NULL%s\n", RED, DEFAULT);
	else
	{
		printf(CYAN);
		printf("Object address: %p\tobject data address:%p\n",
			(void *)obj, obj->data);
		printf(DEFAULT);
	}
}

void	print_camera_infos(const t_camera *camera)
{
	printf("The camera informations:\n");
	printf("The transform component:\n");
	printf("position:\n");
	print_vec3(&camera->transform_comp.transform.position);
	printf("right:\n");
	print_vec3(&camera->transform_comp.right);
	printf("up:\n");
	print_vec3(&camera->transform_comp.up);
	printf("forward:\n");
	print_vec3(&camera->transform_comp.forward);
	printf("\nhorizontal:\n");
	print_vec3(&camera->horizontal);
	printf("vertical:\n");
	print_vec3(&camera->vertical);
	printf("delta_horizontal:\n");
	print_vec3(&camera->delta_horizontal);
	printf("delta_vertical:\n");
	print_vec3(&camera->delta_vertical);
	printf("left bottom:\n");
	print_vec3(&camera->left_bottom);
	printf("pixel00loc:\n");
	print_vec3(&camera->pixel00loc);
}
