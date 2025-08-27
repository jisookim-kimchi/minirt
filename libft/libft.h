/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 20:30:14 by tfarkas           #+#    #+#             */
/*   Updated: 2025/08/18 17:35:11 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include "../garbage/garbage.h"
// # include <stdlib.h>
# include <unistd.h>

int		ft_isalpha(int ch);
int		ft_isdigit(int ch);
int		ft_isalnum(int ch);
int		ft_isascii(int ch);
int		ft_isprint(int ch);
int		ft_strlen(const char *s);
void	*ft_memset(void *str, int ch, unsigned int len);
void	ft_bzero(void *str, unsigned int len);
void	*ft_memcpy(void *dest, const void *src, unsigned int n);
void	*ft_memmove(void *dest, const void *src, unsigned int n);
int		ft_toupper(int ch);
int		ft_tolower(int ch);
void	*ft_memchr(const void *src, int ch, unsigned int n);
int		ft_memcmp(const void *s1, const void *s2, unsigned int n);
int		ft_strlcpy(char *dest, const char *src, unsigned int destsize);
int		ft_strlcat(char *dest, const char *src, unsigned int destsize);
char	*ft_strchr(const char *s, int ch);
char	*ft_strrchr(const char *s, int ch);
int		ft_strncmp(const char *s1, const char *s2, unsigned int n);
char	*ft_strnstr(const char *orig_s, const char *search_s, unsigned int n);
int		ft_atoi(const char *str);
void	*ft_calloc(unsigned int numcount, unsigned int bsize);
char	*ft_strdup(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_itoa(int n);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);

#endif