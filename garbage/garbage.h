/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 06:57:12 by tfarkas           #+#    #+#             */
/*   Updated: 2025/09/02 06:57:13 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// todo i have to think about where put this ..
#include <stdio.h>
#include <stdlib.h>

typedef struct s_garbage_node
{
	void					*data;
	struct s_garbage_node	*next;
}							t_garbage_node;

typedef struct s_garbage_lst
{
	t_garbage_node			head;
}							t_garbage_lst;

void						init_garbage_list(t_garbage_lst *garbage);
t_garbage_node				*do_malloc(void *indata, t_garbage_lst *garbage);
void						add_to_garbage_list(t_garbage_lst *garbage,
								t_garbage_node *new_node);
void						garbage_lst_release(t_garbage_lst *garbage);
void						print_garbage_list(t_garbage_lst *garbage);