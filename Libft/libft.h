/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 11:41:35 by soelalou          #+#    #+#             */
/*   Updated: 2023/11/12 11:41:35 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <strings.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <string.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}			t_list;


void    swap_a(int  *stack);
void     swap_b(int  *stack);
void     swap_ss(int  *stack_a, int *stack_b);
void	push_a(int *stack_a, int *stack_b, int *count_a, int *count_b);
void	push_b(int *stack_a, int *stack_b, int *count_a, int *count_b);
void    organise_a(int *stack, int *count);
void    organise_b(int *stack, int *count);
void    rotate_a(int *stack_a, int *count_a, int *best_a);
void    rotate_b(int *stack_b, int *count_b, int *best_b);
void    rotate_double(int *stack_a, int *count_a, int *stack_b, int *count_b, int *best_a, int *best_b);
void    revers_rotate_a(int *stack_a, int *count_a, int *best_a);
void    revers_rotate_b(int *stack_b, int *count_b, int *best_b);
void    revers_rotate_double(int *stack_a, int *count_a, int *stack_b, int *count_b,  int *best_a, int *best_b);

int    scan_small(int *stack, int *count);
int    scan_big(int *stack, int *count);
// int    wich_one(int above, int under, int *count);
int    final(int *stack, int *count);
int     comp(int start,int *stack_search, int *count_search, int *under, int *above);
int     verif_big(int start,int *stack_search, int *count_search);
int     verif_small(int start,int *stack_search, int *count_search);

void    calcule(int *stack_a, int *stack_b, int count_a, int count_b, int *best_a, int *best_b);
int    nearest_small(int stack_a, int *stack_b, int count);
int     push(int *best_a, int *best_b, int *stack_a, int *stack_b, int count_a, int count_b);
void     three_left(int *stack_a, int count_a);

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_lstsize(t_list *lst);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_nbrlength(long nbr);
int		ft_occ(char *str, char c);
int		ft_printf(const char *format, ...);
int		ft_putaddr_fd(void *adress, int fd);
int		ft_putchar_fd(char c, int fd);
int		ft_putendl_fd(char *str, int fd);
int		ft_puthex_fd(unsigned int nb, char *base, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putunbr_fd(unsigned int nb, int fd);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*get_next_line(int fd);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strcpy(char *s1, const char *s2);
char	*ft_strdup(const char *s);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strnstr(const char *str, const char *tf, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s, char const *set);
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
long	ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	ft_freetab(char **tab);
void	ft_striteri(char*s, void (*f)(unsigned int, char *));
void	*ft_calloc(size_t count, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *str, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstadd_front(t_list **alst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void*));
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *list);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
size_t	ft_strlen(const char *str);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

#endif