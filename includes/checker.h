/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnarbert <mnarbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 13:08:44 by mnarbert          #+#    #+#             */
/*   Updated: 2019/02/15 09:32:52 by mnarbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include <stdio.h>
# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define RESET   "\x1b[0m"

typedef struct	s_struct
{
	int					content;
	int					level;
	struct s_struct		*next;
}				t_struct;

typedef struct	s_info
{
	int					a;
	int					b;
	int					checker;
	t_struct			*stack_a;
	t_struct			*stack_b;
	int					*array_a;
	int					counter;
	int					median;
	int					level;
	int					len;
	int					middle_number;
	int					number;
	int					insertion;
	int					quick;
	int					view;
	int					file;
	int					type;
}				t_info;
typedef	struct	s_key
{
	t_struct			*first_a;
	t_struct			*second_a;
	t_struct			*last_a;
	t_struct			*first_b;
	t_struct			*second_b;
	t_struct			*last_b;
}				t_key;

t_struct		*ft_lstnew_new(int content);
t_struct		*ft_lstadd_new(t_struct **begin_list, int data);
void			ft_lstdel_new(t_struct **alst);
void			ft_lstadd_back(t_struct **begin_list, int content);
int				make_instructions(t_info *len, char *line);
int				check_int(char *argv, t_info *len);
void			operation_sa_sb(t_struct **stack, int len, char *str);
int				operation_pa_pb(t_info *push, int flag, char *str);
void			operation_ra_rb(t_struct **stack, int len, char *str);
void			operation_rra_rrb(t_struct **stack, int len, char *str);
void			error_function(t_info **len);
void			error_without_del(void);
int				check_if_ok(t_struct *stack);
int				check_if_ok_reverse(t_struct *stack);
int				init_len(t_info **len);
void			del_all(t_info **len);
int				make_instructions_first(t_info *len, char *line);
void			make_instructions_second(t_info *len, char *line);
t_struct		*init_key_elements(t_struct *stack, int counter, int len);
void			init_key(t_info *push, t_key *elements);
int				ft_lstunmatch(t_struct *stack, int length);
void			swap_three_a(t_info *push, t_key *el);
void			sort_if_a_less_twenty(t_info *push, t_key *el);
int				finding_median(t_struct *stack, int len);
int				finding_median_b(t_struct *stack, int len);
t_struct		*creating_stack_for_median(t_struct *stack, int len);
int				check_len_level(t_struct *stack);
void			going_throw_stack_a(t_info *push, t_key *el);
void			going_throw_stack_ab(t_info *push, t_key *el);
void			sort_if_a_less_twenty(t_info *push, t_key *el);
int				check_if_only_one_lvl(t_struct *stack);
void			init_for_stack_b(t_info *push, t_key *el);
void			move_if_len_two(t_info *push, t_key *el);
void			printing_stack(t_info *len);
void			printing_stack_extra(int count, t_info *len,
								t_struct *temp_a, t_struct *temp_b);
void			printing_stack_a(int number);
void			printing_stack_b(int number);
int				search_flags(int argc, char **argv, int i, t_info *len);
void			print_usage(int flag);
void			checking_usage(t_info *push, int i, int argc);
void			checking_usage_checker(t_info *len, int i, int argc);
void			check_help_flag(int number);
void			if_all_ints(int i, int argc, t_info *push, char **argv);
void			extrackt_teil_from_going_throw(t_info *push, t_key *el);

#endif
