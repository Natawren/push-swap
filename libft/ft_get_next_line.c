/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnarbert <mnarbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:15:57 by mnarbert          #+#    #+#             */
/*   Updated: 2019/02/06 10:27:08 by mnarbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_write_to_rest(char **str, t_list **list_temp, int i)
{
	if (!((*list_temp)->content = ft_memalloc(ft_strlen(*str) + 1)))
	{
		ft_strdel(str);
		return (0);
	}
	(*list_temp)->content = ft_strcpy((*list_temp)->content, *str + i + 1);
	(*list_temp)->size = ft_strlen(*str + i + 1) + 1;
	return (1);
}

int			ft_write_to_line(t_list **list_temp, char **line, int ret)
{
	char			*str;
	int				i;

	i = -1;
	if (ft_strchr((*list_temp)->content, '\n') != NULL || ret == 0)
	{
		if (!(*line = ft_memalloc((*list_temp)->size))
							|| !(str = ft_memalloc((*list_temp)->size)))
			return (-1);
		str = ft_strcpy(str, (*list_temp)->content);
		ft_lstclear(list_temp);
		while (str[++i] != '\n' && str[i] != '\0')
			(*line)[i] = str[i];
		(*line)[i] = '\0';
		if (str[i] != '\0')
		{
			if (!(ft_write_to_rest(&str, list_temp, i)))
				return (-1);
		}
		ft_strdel(&str);
		return (1);
	}
	return (0);
}

int			ft_write_to_content(t_list **list_temp, char *buf)
{
	char			*str;
	char			*str_temp;
	int				len;

	len = ft_strlen(buf);
	if (!(str = ft_memalloc(len + (*list_temp)->size)))
	{
		ft_lstclear(list_temp);
		return (-1);
	}
	str = ft_strcpy(str, (*list_temp)->content);
	str_temp = ft_strjoin(str, buf);
	ft_strdel(&str);
	ft_lstclear(list_temp);
	(*list_temp)->content = ft_strdup(str_temp);
	if (!((*list_temp)->content))
	{
		ft_strdel(&str_temp);
		return (-1);
	}
	(*list_temp)->size = ft_strlen(str_temp) + 1;
	ft_strdel(&str_temp);
	return (1);
}

int			ft_read_ret(int fd, t_list **list_temp, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];
	int				counter;

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (ft_write_to_content(list_temp, buf) == -1)
			return (-1);
		counter = ft_write_to_line(list_temp, line, ret) == 1;
		if (counter == 1)
			return (1);
		else if (counter == -1)
		{
			ft_lstclear(list_temp);
			return (-1);
		}
	}
	if (ret < 0)
		return (-1);
	if (ret == 0 && (*list_temp)->size > 1)
		return (ft_write_to_line(list_temp, line, ret)) ? 1 : 0;
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static t_list	*list;
	t_list			*list_temp;
	t_list			*list_ptr;
	int				counter;

	if (fd < 0 || !line)
		return (-1);
	list_ptr = list;
	while (list_ptr)
	{
		if ((int)list_ptr->fd == fd)
		{
			list_temp = list_ptr;
			break ;
		}
		list_ptr = list_ptr->next;
	}
	if (!list_ptr)
		ft_lstadd(&list, (list_temp = ft_lstnew(NULL, 0, fd)));
	if (list_temp->size > 0 && ft_strchr(list_temp->content, '\n') != NULL)
		return (ft_write_to_line(&list_temp, line, 1)) ? 1 : 0;
	if ((counter = ft_read_ret(fd, &list_temp, line)) == -1)
		return (-1);
	return (counter == 1) ? 1 : 0;
}
