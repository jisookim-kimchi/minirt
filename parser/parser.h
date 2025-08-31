/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 14:46:39 by jisokim2          #+#    #+#             */
/*   Updated: 2025/08/31 19:58:25 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../mlx_tools.h"

typedef struct s_parser
{
	int	a_count;
	int	c_count;
	int	l_count;
}	t_parser;

//parse.c
int		parsing_start(char *line, t_window *window);
void	free_splited_str(char **to_free);

//parse_file_utils.c
int		count_array_elem(char **tokens);
char	*ft_strtok(char *str, const char c);
bool	is_valid_file(char *path);
int		open_file(char *path);

//parse_file.c
int		read_file(int fd, t_window *window, char *path);

//ACL_parser.c
int		parse_spot_light(const char *line, t_spot_light *light);
int		parse_ambient(char *line, t_ambient *ambient);
int		parse_camera(char *line, t_camera *camera);
int		parse_light(char *line, t_light *light);

//OBJ_parser.c
int		parse_plane(const char *line, t_plane *plane);
int		parse_sphere(const char *line, t_sphere *sphere);
int		parse_cylinder(const char *line, t_cylinder *cylinder);

//parse_utils.c
int		parse_color(char *token, float *red, float *green, float *blue);
void	free_splited_str(char **to_free);

//float or double?
//int		parse_vec3(char *token, float *x, float *y, float *z);
int		parse_vec3(char *token, double *x, double *y, double *z);
int		is_digit(const char *token);
float	ft_atof(const char *str);
#endif
