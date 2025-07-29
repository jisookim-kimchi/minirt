/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 14:46:39 by jisokim2          #+#    #+#             */
/*   Updated: 2025/07/29 15:23:30 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../mlx_tools.h"

//parse.c
int		parsing_start(char *line, t_window *window);

//parse_file.c
bool	is_valid_file(char *path);
int		open_file(char *path);
int		read_file(int fd, t_window *window);

//ACL_parser.c
int		parse_ambient(char *line, t_ambient *ambient);
int		parse_camera(char *line, t_camera *camera);
int		parse_light(char *line, t_light *light);

//parse_utils.c
int		count_array_elem(char **tokens);
char 	*ft_strtok(char *str, const char c);
int		parse_color(char *token, float *red, float *green, float *blue);

//float or double?
//int		parse_vec3(char *token, float *x, float *y, float *z);
int		parse_vec3(char *token, double *x, double *y, double *z);
int		is_digit(const char *token);
float	ft_atof(char *str);
#endif
