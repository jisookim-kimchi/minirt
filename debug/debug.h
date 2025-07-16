/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:36:33 by tfarkas           #+#    #+#             */
/*   Updated: 2025/07/16 20:03:06 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "../math/mathheader.h"

void	print_vec3(const t_vec3 * vec3);
void	print_color_float(const t_color_float *float_color);
void	print_sphere_infos(const t_sphere *sphere);
void	print_objs(t_objs_list *obj);
void	print_hit_t(const t_hit *hit);

#endif