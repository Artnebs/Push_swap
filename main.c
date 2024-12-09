#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack *a;
	t_stack *b;

	a = parse_arguments(ac, av);
	if (!a)
		return (1);
	if (is_sorted(a))
	{
		free_stack(a);
		return (0);
	}
	b = init_stack();
	if (a->size <= 3)
		sort_three(a);
	else if (a->size <= 5)
		sort_five(a, b);
	else
		quick_median_sort(a, b);
	while (b->size > 0)
		merge_stacks(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
