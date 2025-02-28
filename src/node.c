/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:38:55 by masmar            #+#    #+#             */
/*   Updated: 2024/08/06 12:38:55 by masmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Updates the highest and lowest values in stack A
// of the ht_list structure when a new number is added
static void	set_higher_lower(t_ht_list *ht_list, int nbr)
{
	if (nbr > ht_list->highest_a->nbr)
	{
		ht_list->highest_a = ht_list->bottom_a;
		ht_list->highest_a->nbr = nbr;
	}
	if (nbr < ht_list->lowest_a->nbr)
	{
		ht_list->lowest_a = ht_list->bottom_a;
		ht_list->lowest_a->nbr = nbr;
	}
}

// Adds a new node with a given value
// to the bottom of the stack a in ht_list
static t_node	*append_node(int value, t_ht_list *ht_list)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->nbr = value;
	new->next = NULL;
	new->prev = ht_list->bottom_a;
	new->index = ht_list->length_a;
	if (ht_list->head_a == NULL)
	{
		ht_list->head_a = new;
		ht_list->bottom_a = new;
		ht_list->highest_a = new;
		ht_list->lowest_a = new;
	}
	else
	{
		ht_list->bottom_a->next = new;
		ht_list->bottom_a = new;
	}
	ht_list->length_a++;
	set_higher_lower(ht_list, value);
	return (new);
}

// Checks for duplicates in stack a
static char	*check_dup(int nbr, t_ht_list *ht_list, char	**arg_split)
{
	t_node	*current;
	t_node	*next;

	current = ht_list->head_a;
	while (current != NULL)
	{
		next = current->next;
		if (nbr == current->nbr)
		{
			ft_free(arg_split);
			error(ht_list);
		}
		current = next;
	}
	return (NULL);
}

// Checks if any number in the split argument array exceed a length
// which would imply they are larger than INT_MAX
static void	check_max(t_ht_list *ht_list, char	**arg_split)
{
	int	i;
	int	j;

	i = 0;
	while (arg_split[i])
	{
		j = 0;
		while (arg_split[i][j] == '0' || arg_split[i][j] == '+'
				|| arg_split[i][j] == '-')
			j++;
		if (ft_strlen(&arg_split[i][j]) > 11)
		{
			ft_free(arg_split);
			error(ht_list);
		}
		i++;
	}
}

// Initializes the nodes in stack a, based on the input string arg
void	init_node(char *arg, t_ht_list *ht_list)
{
	char	**arg_split;
	int		i;
	int		err;
	int		nbr;

	arg_split = ft_split(arg, ' ');
	free(arg);
	i = 0;
	err = 0;
	check_max(ht_list, arg_split);
	while (arg_split[i])
	{
		nbr = ft_atoi(arg_split[i++], &err);
		check_dup(nbr, ht_list, arg_split);
		append_node(nbr, ht_list);
		if (err)
		{
			ft_free(arg_split);
			error(ht_list);
		}
	}
	ft_free(arg_split);
}
