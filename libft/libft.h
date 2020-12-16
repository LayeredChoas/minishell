/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:33:24 by ayennoui          #+#    #+#             */
/*   Updated: 2020/12/16 19:13:44 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBFT_H
# define _LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# define BUFFER_SIZE 100

size_t			ft_strlen(const char *str);
long long		ft_atoi(const char *str);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_strncmp(const char *str1, const char *str2, size_t n);
char			*ft_strnstr(const char *str, const char *ned, size_t len);
int				ft_tolower(int c);
int				ft_toupper(int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s1);
size_t			ft_strlcat(char *dest, const char *src, size_t n);
char			*ft_substr(char const *s, unsigned int start, size_t len);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			ft_bzero(void *s, size_t n);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
void			ft_putnbr_fd(int n, int fd);
void			*ft_calloc(size_t count, size_t size);
typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **alst, t_list *lst1);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **alst, t_list *lst1);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *l, void *(*f)(void *), void (*del)(void *));
int				return_f(char **tab, int n, char **line, int fd);
int				get_next_line(int fd, char **line);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
#endif
