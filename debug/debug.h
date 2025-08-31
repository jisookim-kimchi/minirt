/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:36:33 by tfarkas           #+#    #+#             */
/*   Updated: 2025/08/31 20:31:31 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "../math/mathheader.h"

void	print_vec3(const t_vec3 *vec3);
void	print_color_float(const t_color_float *float_color);
void	print_color_compare(const t_color_float *float_color1,
			const t_color_float *float_color2);
void	print_sphere_infos(const t_sphere *sphere);
void	print_plane_infos(const t_plane *plane);
void	print_cylinder_infos(const t_cylinder *cylinder);
void	print_objs(t_objs_list *obj);
void	print_hit_t(const t_hit *hit);
void	pointer_address_message(void *ptr);
void	object_adress(t_objs_list *obj);
void	print_camera_infos(const t_camera *camera);

#endif