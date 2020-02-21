/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 15:28:53 by asulliva       #+#    #+#                */
/*   Updated: 2020/02/21 17:50:54 by abumbier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

/*
**	@desc	- initialized the file to be opened
**	@param	- int ac, the number of arguments
**			- char **av, the arguments
**	@return	- t_asm *data, open file and malloced struct
*/

static t_asm	*init(int ac, char **av)
{
	t_asm	*data;

	data = (t_asm*)ft_memalloc(sizeof(t_asm));
	data->parts = NULL;
	data->labels = NULL;
	data->lines = 0;
	data->char_name = av[ac - 1];
	data->rfd = open(av[ac - 1], O_RDONLY);
	if (data->rfd < 3 || read(data->rfd, data->name, 0) < 0)
		return (NULL);
	return (data);
}

void			print_parts(t_parts *parts)
{
	t_parts	*curr;

	curr = parts;
	while (curr)
	{
		printf("__%s__\n", curr->name);
//		free(curr->name);
		curr = curr->next;
	}
}

/*
**	@desc	- function checks if the file is a .s file
**	@param	- char *file, name of the file given as argument
*/

static void		check_file(char *file)
{
	int		len;

	len = ft_strlen(file);
	if (file[len - 1] == 's' && file[len - 2] == '.')
		return ;
	else
		error("File exstension must be .s", 0);
}

int				main(int ac, char **av)
{
	t_asm	*data;

	if (ac < 2)
		error("usage", 0);
	check_file(av[ac - 1]);
	data = init(ac, av);
	if (!data)
		error("Invalid file", 0);
	parse(data);
	close(data->rfd);
	printf("\n\n***   AFTER PARSE   ***\n\n");
	print_parts(data->parts);
//	check_syntax(data->parts);
//	create_cor(data);
//	close(data->wfd);
//	free_data(data);
//	while (1);
	return (0);
}
