/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 10:36:29 by ayajrhou          #+#    #+#             */
/*   Updated: 2021/07/06 10:36:31 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*suivant;
	struct s_stack	*preced;
}   t_stack;

typedef struct s_list
{
	struct s_stack	*header;
	struct s_stack	*footer;
}   t_list;

void	ft_depiler(t_list *head)
{
	t_stack	*to_delete;
	t_stack	*a;

	if (head != NULL && head->header != NULL)
	{
		to_delete = head->header;
		if (!to_delete->suivant)
		{
			free(to_delete);
			head->header = NULL;
			head->footer = NULL;
			to_delete = NULL;
		}
		else
		{
			a = to_delete->suivant;
			head->header = a;
			a->preced = NULL;
			free(to_delete);
			to_delete = NULL;
		}
	}
}

void	ft_remplir(t_list *head, int val, int index)
{
	t_stack	*a;
	t_stack	*to_add;

	to_add = malloc(sizeof(t_stack));
	if (!to_add)
		exit(0);
	if (head->header == NULL)
	{
		to_add->index = index;
		to_add->value = val;
		to_add->suivant = NULL;
		to_add->preced = NULL;
		head->footer = to_add;
		head->header = to_add;
	}
	else
	{
		a = head->header;
		to_add->index = index;
		to_add->value = val;
		to_add->suivant = a;
		to_add->preced = NULL;
		a->preced = to_add;
		head->header = to_add;
	}
}

int main(int argc , char **argv)
{
    int i;
    int c = 0;
    i = 1;
    t_list	*header;
    t_stack *a;

    if (argc > 2)
    {
        header = malloc(sizeof(t_list));
		header->header = NULL;
        while(argc - 1 > c)
        {
            ft_remplir(header, atoi(argv[i]), 0);
            c++;
            i++;
        }
    }
    a = header->header;
    while (a != NULL)
    {
        printf("%d\n", a->value);
        a = a->suivant;
    }
    
}