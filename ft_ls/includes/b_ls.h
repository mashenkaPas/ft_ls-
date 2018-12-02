/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ls.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpas <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 19:02:43 by mpas              #+#    #+#             */
/*   Updated: 2018/11/30 15:01:23 by mpas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_LS_H
# define B_LS_H

# include <pwd.h>
# include <grp.h>
# include <string.h>
# include <errno.h>
# include <time.h>
# include <stdlib.h>
# include <unistd.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <uuid/uuid.h>
# include "../b_printf/libftprintf.h"

# define CRED  "\x1B[0;31m"
# define CBLUE  "\x1B[0;34m"
# define CPINK  "\x1B[0;35m"
# define CWHITE  "\x1B[39m"
# define BBLUE	"\x1B[46m"
# define BBLACK "\x1B[40m"
# define BYELLOW "\x1B[43m"

typedef struct		s_list
{
	char			*name;
	struct stat		buf;
	struct s_list	*next;
}					t_node;

int					g_flag_a;
int					g_flag_l;
int					g_flag_t;
int					g_flag_r;
int					g_flag_g;
int					g_flag_sc;
int					g_flag_tc;
int					g_flag_gc;
int					g_entity_fill;
int					g_flag_illegal;
int					g_flag_recursion;

int					ft_strlen(const char *s);
void				d_blocks(t_node *path);
int					ft_strcmp(char *s1, char *s2);
char				*ft_strcat(char *s1, char *s2);
int					node_size(t_node *begin_list);
t_node				*fl_apply(t_node *node_list);
t_node				*path_search_errors(t_node *path);
t_node				*path_apply_flag(t_node *path);
void				mode_print(mode_t mode);
void				d_dirs(t_node *path, int rec);
void				node_swap(t_node *one, t_node *two);
void				node_copy(t_node *src, t_node *dst);
t_node				*node_remove_hidden(t_node *begin_list);
t_node				*node_sort_by_name(t_node *info, int is_asc);
void				fl_init();
char				*delete_slash(char *str);
void				ft_list_clean(t_node **list);
char				*getting_full_symlink(char *link, char *path);
int					ft_str_find(char *s1, char *s2);
void				fl_set(char *str);
char				*help_func(char *link, char *path);
t_node				*node_sort_by_time(t_node *info, int is_asc);
t_node				*node_sort_by_size(t_node *info, int is_asc);
t_node				*node_add(t_node *info, char *name, struct stat buf);
char				*getting_full_symlink(char *link, char *path);
long long			count_blocks(t_node *entity);
void				d_files(t_node *path);
void				d_entity(t_node *path, t_node *entity);
void				d_symlink(t_node *path);
char				*ft_strdup(char *s1);
void				print_with_colors(t_node *entity);
char				*ft_update(char *str, char *update);
char				*ft_strjoin(char const *s1, char const *s2);
t_node				*only_dirs_fill(t_node *path, t_node *list);

#endif
