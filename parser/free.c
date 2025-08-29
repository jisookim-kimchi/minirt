/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 12:35:42 by jisokim2          #+#    #+#             */
/*   Updated: 2025/08/29 12:35:43 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	free_splited_str(char **to_free)
{
	int	i;

	i = 0;
	while (to_free[i])
	{
		free (to_free[i]);
		to_free[i] = NULL;
		i++;
	}
	free (to_free);
	to_free = NULL;
}
