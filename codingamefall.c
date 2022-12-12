/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codingamefall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:15:38 by audreyer          #+#    #+#             */
/*   Updated: 2022/12/13 00:12:04 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct s_pos
{
	struct s_list	*start;
	int				*size;
}	t_pos;

typedef struct s_list
{
	struct s_list	*next;
	struct s_list	*back;
	void			*content;
	struct s_pos	*pos;
}	t_list;

enum	e_proprio
{
	lui = -1,
	personne,
	moi
};

typedef struct s_case
{
	int dechetnbr;
	int proprio;
	int unitnbr;
	int recycleur;
	int canbuild;
	int canspawn;
	int recycleurrange;
}	t_case;

typedef struct s_data
{
	t_pos	*garbage;
	int		largeur;
	int		hauteur;
	int		mymoney;
	int		enmoney;
	t_case	**plateau;
}	t_data;

t_pos		*ft_setpos(t_pos *garbage);
void		ft_lstdelone(t_list *lst, int garbage);
t_list		*ft_lstnew(void *content, t_pos *pos, t_pos *garbage);
void		ft_posclear(t_pos *pos, int garbage);
void		*ft_malloc(int size, t_pos *garbage);



void	ft_lstdelone(t_list *list, int garbage)
{
	if (garbage != 0)
		free(list->content);
	*list->pos->size = *list->pos->size - 1;
	if (list->pos->start->back == list->pos->start)
		list->pos->start = 0;
	else
	{
		if (list->pos->start == list)
			list->pos->start = list->next;
		list->back->next = list->next;
		list->next->back = list->back;
	}
	if (garbage != 0)
		free(list);
}

t_list	*ft_lstnew(void *content, t_pos *pos, t_pos *garbage)
{
	t_list	*liste;

	liste = ft_malloc(sizeof(*liste), garbage);
	if (liste == 0)
		return (0);
	liste->content = content;
	liste->pos = pos;
	*liste->pos->size = *liste->pos->size + 1;
	if (pos->start == 0)
	{
		liste->next = liste;
		liste->back = liste;
		pos->start = liste;
	}
	else
	{
		liste->back = pos->start->back;
		liste->next = pos->start;
		if (*pos->size == 1)
			pos->start->next = liste;
		else
			pos->start->back->next = liste;
		pos->start->back = liste;
	}
	return (liste);
}

void	*ft_malloc(int size, t_pos *garbage)
{
	void	*new;

	new = malloc(size);
	if (new == 0)
		return (0);
	if (garbage != 0)
	{
		ft_lstnew(new, garbage, 0);
		if (garbage->start->back == 0)
		{
			free(new);
			return (0);
		}
	}
	return (new);
}

void	ft_posclear(t_pos *pos, int freee)
{
	if (pos != NULL)
	{
		while (*pos->size != 0)
			ft_lstdelone(pos->start, freee);
		if (freee == 2)
		{
			free(pos->size);
			free(pos);
		}
	}
}

t_pos	*ft_setpos(t_pos *garbage)
{
	t_pos	*pos;
	int		*size;

	size = ft_malloc(sizeof(*size), garbage);
	if (size == 0)
		return (0);
	pos = ft_malloc(sizeof(*pos), garbage);
	if (pos == 0)
	{
		if (garbage == 0)
			free(size);
		return (0);
	}
	pos->size = size;
	pos->start = 0;
	*size = 0;
	return (pos);
}

void	ft_exit(t_data *data, char *str)
{
	if (str)
		printf("%s",str);
	if (data)
		ft_posclear(data, 2);
}

t_data	*ft_init(void)
{
	t_data	*data;
	t_pos	*garbage;

	garbage = ft_setpos(0);
	if (!garbage)
		ft_exit(0, "error malloc\n");
	data = ft_malloc(sizeof(t_data), garbage);
	if (!data)
		ft_exit(data, "error malloc\n");
	data->garbage = garbage;
}

void	ft_parsedata(t_data *data)
{
	scanf("%d%d", &data->mymoney, &data->enmoney);
	for (int i = 0; i < data->hauteur; i++)
	{
		for (int j = 0; j < data->largeur; j++)
		{
			t_case	*case1;

			case1 = &data->plateau[i][j];
			scanf("%d%d%d%d%d%d%d", &case1->dechetnbr, &case1->proprio, &case1->unitnbr, &case1->recycleur, &case1->canbuild, &case1->canspawn, &case1->recycleurrange);
		}
	}
}

void	ft_movetroup(t_data	*data)
{
		int	test;

		test = 0;
			for (int i = 0; i < data->hauteur; i++)
			{
				for (int j = 0; j < data->largeur; j++)
				{
					if (data->plateau[i][j].proprio == moi && data->plateau[i][j].unitnbr > 0)
					{
						printf("MOVE %d %d %d %d %d;", data->plateau[i][j].unitnbr, j, i, j - 1, i);
						test++;
					}
				}
			}
		if (test != 1)
			printf("WAIT;");
		printf("\n");
	
}

void	ft_plateauinit(t_data *data)
{
	data->plateau = ft_malloc(sizeof(t_case *) * (data->hauteur + 1), data->garbage);
	if (!data->plateau)
		ft_exit(data, "error malloc\n");
	data->plateau[data->hauteur] = 0;
	for (int i = 0; i < data->hauteur; i++)
	{
		data->plateau[i] = ft_malloc(sizeof(t_data) * (data->largeur + 1), data->garbage);
		if (!data->plateau[i])
			ft_exit(data, "error malloc\n");
		for (int j = 0; j < data->largeur; j++)
			data->plateau[i][j] = 0;
	}
}

int main()
{
	t_data	*data;
	data = ft_init();
	scanf("%d%d", &data->largeur, &data->hauteur);
	ft_plateauinit(data);
	while (1)
	{
		ft_parsedata(data);
		ft_movetroupe(data);
	}
	ft_exit(data, 0);
}
