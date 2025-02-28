/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:39:08 by masmar            #+#    #+#             */
/*   Updated: 2024/08/06 12:39:09 by masmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Initializes the ht_list structure that manages 2 stacks
static t_ht_list	*init_list(t_ht_list *ht_list)
{
	ht_list = malloc(sizeof(t_ht_list));
	if (!ht_list)
		return (NULL);
	ht_list->highest_a = NULL;
	ht_list->head_a = NULL;
	ht_list->bottom_a = NULL;
	ht_list->length_a = 0;
	ht_list->highest_b = NULL;
	ht_list->head_b = NULL;
	ht_list->bottom_b = NULL;
	ht_list->length_b = 0;
	return (ht_list);
}

// Entry point of the program
int	main(int ac, char **av)
{
	char		*arg;
	t_ht_list	*ht_list;

	if (ac == 1)
		return (1);
	arg = parsing(ac, av);
	ht_list = NULL;
	ht_list = init_list(ht_list);
	if (!ht_list)
		return (1);
	init_node(arg, ht_list);
	if (!check_is_sort(ht_list->head_a))
		sort(ht_list);
	free_list(ht_list);
	return (0);
}
