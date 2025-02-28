/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:38:02 by masmar            #+#    #+#             */
/*   Updated: 2024/08/06 12:38:03 by masmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Checks if elements in stack a are in descending order
static int	check_reverse(t_ht_list *ht_list)
{
	t_node	*head_a;
	int		i;
	int		size;

	head_a = ht_list->head_a;
	i = 1;
	size = ht_list->length_a;
	while (head_a && i != size)
	{
		if (head_a->nbr > head_a->next->nbr)
			i++;
		head_a = head_a->next;
		if (!head_a->next)
			break ;
	}
	if (i == size)
		return (1);
	return (0);
}

// Checks wheter stack a is reversed
// and performs appropriate rotation
void	is_reversed(t_ht_list *ht_list)
{
	if (check_reverse(ht_list) == 1)
		reverse_rotate(ht_list, 'a');
	else
		rotate(ht_list, 'a');
}

// Checks if a linked list a is sorted and in ascending order
bool	check_is_sort(t_node *a)
{
	if (!a)
		return (false);
	while (a->next)
	{
		if (a->nbr > a->next->nbr)
			return (false);
		a = a->next;
	}
	return (true);
}

// Determines the range of numbers to consider
// when moving elements between stacks,
// based on the size of stack a
int	get_ranges(t_ht_list *ht_list)
{
	int	length_a;

	length_a = ht_list->length_a;
	if (length_a >= 6 && length_a <= 16)
		return (3);
	else if (length_a <= 100)
		return (13);
	else if (length_a <= 500)
		return (30);
	else
		return (45);
}

// Creates a copy of the numbers in stack a as an array
int	*copy_arr(t_ht_list *ht_list)
{
	t_node	*head_a;
	int		*arr;
	int		i;

	i = 0;
	arr = malloc(sizeof(int) * ht_list->length_a);
	if (!arr)
		return (NULL);
	head_a = ht_list->head_a;
	while (head_a)
	{
		arr[i] = head_a->nbr;
		head_a = head_a->next;
		i++;
	}
	return (arr);
}
