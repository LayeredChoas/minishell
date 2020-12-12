/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayennoui <ayennoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 19:49:56 by ayennoui          #+#    #+#             */
/*   Updated: 2020/12/12 11:50:57 by ayennoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <signal.h>
# include <dirent.h>
# include <sys/wait.h>
# include "../libft/libft.h"

typedef struct	s_env
{
	char	*key;
	char	*value;
	int		end;
}				t_env;

typedef struct	s_paths
{
	char *home;
	char *pwd;
	char *oldpwd;
}				t_paths;

typedef struct	s_red
{
	int		in;
	int		out;
	char	*cmd;
	char	*arg;
}				t_red;

t_env			*ft_add_to_tab(t_env *tab, char *key, char *value);
t_env			*ft_copy_tab(t_env *tab);
t_env			*ft_remove_tab(t_env *tab, char *key);
t_env			*ft_remove_key(t_env *tab, int x);
void			ft_catch_signal();
void			ft_run_minishell();
int				init(void);
char			*ft_cpy_after(char *s1, char c);
char			*ft_cpy_stop(char *s1, char c);
int				ft_white_space_fix(char *s);
int				ft_change_char(char *str, char change, char to);
char			**ft_adv_split(char *s, char c);
int				ft_check_errors_global(char *str);
int				ft_check_red(char *str);
void			ft_pipe(char *str);
char			*ft_strcut(char *str, int start, int len);
int				ft_skip_q(char *str, char type);
void			ft_args_add(char **cmd);
void			ft_free(char *str);
char			*ft_rewrite(char *str1);
char			*ft_address_fun(char *str);
char			*ft_addr(char *str, int start, int *num);
void			ft_fix_mid(char *str);
void			ft_slash(char *str);
void			ft_free_double(char **str);
void			ft_env_str(void);
void			ft_options(char *str);
int				ft_check_key_error(char *key);
char			*ft_find_key(char *str);
void			ft_red_fun(char *str);
int				ft_pipe_f(int fd, char *str);
void			ft_pipe_l(int fd, char *str);
int				ft_putstr(char *str);
int				ft_putchar(char c);
void			ft_unset(char **str);
char			**ft_rewrite_com(char **re_com);
int				ft_str2dlen(char **str);
void			ft_cd(char **str);
void			ft_echo(char **str);
void			ft_exit(char **com);
void			ft_env(void);
void			ft_export(char **str);
void			ft_pwd(void);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_tab_len(t_env *tab);
void			ft_init_pwd();
int				ft_error_print(char *str, int ret);
char			*ft_super_join(char *s1, char *s2, char *s3);
void			ft_init_paths(void);
int				ft_check_file(char *file);
int				ft_create_file(char *file);
int				ft_status_num(int num);
void			ft_execve_run(char **str);
int				ft_path_coms(char **com);
void			ft_fix_paths(char **path);
void			ft_free_env(t_env *str);
int				ft_test_semi(char **cmd);
void			ft_export_key_save(char *str);
void			ft_update_back(char *key);
char			**ft_char_add(char **tab, char *add);
void			ft_update_back(char *key);
int				ft_check_tab(char **tab, char *add);
char			**ft_find_path(void);
char			*ft_export_error(char *com);
int				ft_test_pipe(char **com);
void			ft_red_out_1(char **cmd);
void			ft_red_out_app(int ap, int start, char *out);
void			ft_red_in_1(char **cmd);
void			ft_free_four(char *s1, char *s2, char *s3, char *s4);
int				ft_address_test(char *str);
char			*ft_address_fun(char *str);
int				ft_skip_q(char *str, char type);
void			ft_ctrl_slash(int nb);
char			*ft_paths_ret(char *str);
int				ft_home_check(char *str);

t_env			*g_env_tab;
t_paths			g_paths;
t_red			g_red;
char			*g_parse_line;
char			**g_env_str;
char			**g_env_back;
char			*g_syntax_semi;
char			*g_syntax_pipe;
char			*g_syntax_red;
int				g_file_error;
int				g_fail;
int				g_in;
int				g_out;
int				g_exit;
int				g_fail;
int				g_pp;
int				g_fork_id;
int				g_fork_work;
int				g_i;
int				g_id_mini;
char			*g_last_cmd;
char			*g_exec_name;
#endif
