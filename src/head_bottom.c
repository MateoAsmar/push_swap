/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head_bottom.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:38:50 by masmar            #+#    #+#             */
/*   Updated: 2024/08/06 12:38:51 by masmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Returns the head node of either stack a or b
// in ht_list, based on list parameter
t_node	*get_head(t_ht_list *ht_list, char list)
{
	t_node	*head;

	if (list == 'a')
		head = ht_list->head_a;
	else if (list == 'b')
		head = ht_list->head_b;
	else
		return (NULL);
	return (head);
}

// Returns the bottom node of either stack a or b
// in ht_list based on the list parameter
t_node	*get_bottom(t_ht_list *ht_list, char list)
{
	t_node	*bottom;

	if (list == 'a')
		bottom = ht_list->bottom_a;
	else if (list == 'b')
		bottom = ht_list->bottom_b;
	else
		return (NULL);
	return (bottom);
}

// Updates the head and bottom pointers of either
// stack a or b in ht_list based on list parameter
void	update_headbottom(t_ht_list *ht_list, t_node *head
		, t_node *bottom, char list)
{
	if (list == 'a')
	{
		if (head)
			ht_list->head_a = head;
		if (bottom)
			ht_list->bottom_a = bottom;
	}
	else if (list == 'b')
	{
		if (head)
			ht_list->head_b = head;
		if (bottom)
			ht_list->bottom_b = bottom;
	}
	update_highest_lowest(ht_list);
}

// Finds either the highest or lowest value node
// in a stack (depending on get_value) and returns it
static t_node	*get_bounds(t_ht_list *ht_list, char list, int get_value)
{
	t_node	*current;
	t_node	*bounds;
	int		bounds_value;
	int		i;

	current = get_head(ht_list, list);
	if (current == NULL)
		return (NULL);
	bounds = current;
	bounds_value = current->nbr;
	i = 0;
	while (current)
	{
		current->index = i;
		i++;
		if ((get_value && current->nbr > bounds_value)
			|| (!get_value && current->nbr < bounds_value))
		{
			bounds_value = current->nbr;
			bounds = current;
		}
		current = current->next;
	}
	return (bounds);
}

// Updates the highest and lowest value nodes
// in both stack a and b in ht_list
void	update_highest_lowest(t_ht_list *ht_list)
{
	t_node	*bounds;

	bounds = get_bounds(ht_list, 'a', 1);
	ht_list->highest_a = bounds;
	bounds = get_bounds(ht_list, 'b', 1);
	ht_list->highest_b = bounds;
	bounds = get_bounds(ht_list, 'a', 0);
	ht_list->lowest_a = bounds;
	bounds = get_bounds(ht_list, 'b', 0);
	ht_list->lowest_b = bounds;
}
