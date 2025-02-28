/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:38:21 by masmar            #+#    #+#             */
/*   Updated: 2024/08/06 12:38:22 by masmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Frees all nodes ina  linked list,
// either head_a or head_b based on the list parameter
static void	free_target_list(t_ht_list *ht_list, char list)
{
	t_node	*current;
	t_node	*next;

	current = NULL;
	if (list == 'a')
		current = ht_list->head_a;
	else if (list == 'b')
		current = ht_list->head_b;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

// Frees all resources associated with both linked lists
// and then frees the ht_list strcuture itself
void	free_list(t_ht_list *ht_list)
{
	free_target_list(ht_list, 'a');
	free_target_list(ht_list, 'b');
	free(ht_list);
}

// Handles error situations by printing an error message,
// freeing resources, and terminating the program
void	error(t_ht_list *ht_list)
{
	write(1, "Error\n", 6);
	if (ht_list)
		free_list(ht_list);
	exit(1);
}
