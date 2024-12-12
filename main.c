#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>


// Prints the state of the stacks (minimal debug version)
void print_stack_state(const char *msg, t_stack *stack_a, t_stack *stack_b)
{
    printf("\n%s\n", msg);
    if (stack_a)
    {
        printf("Stack A: [Size: %d] ", stack_a->size);
        t_node *current = stack_a->top;
        while (current)
        {
            printf("%d ", current->value);
            current = current->next;
        }
        printf("\n");
    }
    else
        printf("Stack A: NULL\n");

    if (stack_b)
    {
        printf("Stack B: [Size: %d] ", stack_b->size);
        t_node *current = stack_b->top;
        while (current)
        {
            printf("%d ", current->value);
            current = current->next;
        }
        printf("\n");
    }
    else
        printf("Stack B: NULL\n");
}

int main(void)
{
    t_stack *stack_a = init_stack();

    // Test with a sorted stack
    push_bottom(stack_a, 1);
    push_bottom(stack_a, 2);
    push_bottom(stack_a, 3);
    push_bottom(stack_a, 5);
    push_bottom(stack_a, 6);

    int position = get_insert_position(stack_a, 4);
    printf("Insert Position for 4: %d\n", position);  // Should return 3 as it fits between 3 and 5

    // Test with an unsorted stack
    t_stack *stack_b = init_stack();
    push_bottom(stack_b, 5);
    push_bottom(stack_b, 3);
    push_bottom(stack_b, 2);
    push_bottom(stack_b, 1);
    push_bottom(stack_b, 4);

    position = get_insert_position(stack_b, 4);
    printf("Insert Position for 4 in unsorted stack: %d\n", position);  // Should find the correct position using linear search

    free_stack(stack_a);
    free_stack(stack_b);

    return 0;
}


/*
// Prints the state of the stacks (minimal debug version)
void print_stack_state(const char *msg, t_stack *stack_a, t_stack *stack_b)
{
    printf("\n%s\n", msg);
    if (stack_a)
    {
        printf("Stack A: [Size: %d] ", stack_a->size);
        t_node *current = stack_a->top;
        while (current)
        {
            printf("%d ", current->value);
            current = current->next;
        }
        printf("\n");
    }
    else
        printf("Stack A: NULL\n");

    if (stack_b)
    {
        printf("Stack B: [Size: %d] ", stack_b->size);
        t_node *current = stack_b->top;
        while (current)
        {
            printf("%d ", current->value);
            current = current->next;
        }
        printf("\n");
    }
    else
        printf("Stack B: NULL\n");
}

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    int median;
    int smallest_value, insert_position;

    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <numbers>\n", argv[0]);
        return (EXIT_FAILURE);
    }

    // Initialize stacks
    stack_a = parse_arguments(argc, argv);
    stack_b = init_stack();

    if (!stack_a || !stack_b)
    {
        fprintf(stderr, "Error: Stack initialization failed\n");
        free_stack(stack_a);
        free_stack(stack_b);
        return (EXIT_FAILURE);
    }

    print_stack_state("Initial Stacks", stack_a, stack_b);

    // Test find_median
    median = find_median(stack_a);
    printf("Median: %d\n", median);

    // Test get_smallest
    smallest_value = get_smallest(stack_a);
    printf("Smallest Value in Stack A: %d\n", smallest_value);

    // Test get_position
    printf("Position of %d in Stack A: %d\n", smallest_value, get_position(stack_a, smallest_value));

    // Test get_insert_position
    insert_position = get_insert_position(stack_a, median);
    printf("Insert Position for %d in Stack A: %d\n", median, insert_position);

    // Test calc_rotations_for_a and calc_rotations_for_b
    printf("Rotations in A for Position %d: %d\n", insert_position, calc_rotations_for_a(stack_a, insert_position));

    if (stack_b->size > 0) // Only test if Stack B has elements
    {
        printf("Rotations in B for Position %d: %d\n", 0, calc_rotations_for_b(stack_b, 0));
    }

    // Test push_swap
    push_swap(stack_a, stack_b); // Apply the sorting logic

    print_stack_state("After push_swap", stack_a, stack_b);

    // Free resources
    free_stack(stack_a);
    free_stack(stack_b);

    return (EXIT_SUCCESS);
}

// Prints the state of the stacks
void print_stack_state(const char *msg, t_stack *stack_a, t_stack *stack_b)
{
    printf("\n%s\n", msg);
    if (stack_a)
    {
        printf("Stack A: [Size: %d]\n", stack_a->size);
        t_node *current = stack_a->top;
        while (current)
        {
            printf("%d ", current->value);
            current = current->next;
        }
        printf("\n");
    }
    else
        printf("Stack A: NULL\n");

    if (stack_b)
    {
        printf("Stack B: [Size: %d]\n", stack_b->size);
        t_node *current = stack_b->top;
        while (current)
        {
            printf("%d ", current->value);
            current = current->next;
        }
        printf("\n");
    }
    else
        printf("Stack B: NULL\n");
}

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    int median;

    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <numbers>\n", argv[0]);
        return (EXIT_FAILURE);
    }

    // Initialize stacks
    stack_a = parse_arguments(argc, argv);
    stack_b = init_stack();

    if (!stack_a || !stack_b)
    {
        fprintf(stderr, "Error: Stack initialization failed\n");
        free_stack(stack_a);
        free_stack(stack_b);
        return (EXIT_FAILURE);
    }

    print_stack_state("Initial Stacks", stack_a, stack_b);

    // Check if stack_a is already sorted
    if (is_sorted(stack_a))
    {
        printf("Stack is already sorted. No operations needed.\n");
        free_stack(stack_a);
        free_stack(stack_b);
        return (EXIT_SUCCESS);
    }

    // Test find_median
    median = find_median(stack_a);
    printf("Median: %d\n", median);

    // Partition the stack based on the median
    partition_stack(stack_a, stack_b, median, stack_a->size);

    print_stack_state("After Partition", stack_a, stack_b);

    // Sort remaining elements in stack_a
    sort_three(stack_a);

    // Merge stacks
    while (stack_b->size > 0)
        move_with_min_cost(stack_a, stack_b, stack_b->top->value);

    print_stack_state("After Sorting", stack_a, stack_b);

    // Free resources
    free_stack(stack_a);
    free_stack(stack_b);

    return (EXIT_SUCCESS);
}

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    int median;
    int smallest_value, insert_position;

    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <numbers>\n", argv[0]);
        return (EXIT_FAILURE);
    }

    // Initialize stacks
    stack_a = parse_arguments(argc, argv);
    stack_b = init_stack();

    if (!stack_a || !stack_b)
    {
        fprintf(stderr, "Error: Stack initialization failed\n");
        free_stack(stack_a);
        free_stack(stack_b);
        return (EXIT_FAILURE);
    }

    print_stack_state("Initial Stacks", stack_a, stack_b);

    // Test: Is the stack sorted
    printf("Is Stack A Sorted? %s\n", is_sorted(stack_a) ? "Yes" : "No");

    // Test: Find median
    median = find_median(stack_a);
    printf("Median: %d\n", median);

    // Test: Get smallest value
    smallest_value = get_smallest(stack_a);
    printf("Smallest Value in Stack A: %d\n", smallest_value);

    // Test: Get position of smallest value
    printf("Position of %d in Stack A: %d\n", smallest_value, get_position(stack_a, smallest_value));

    // Test: Get insert position for the median
    insert_position = get_insert_position(stack_a, median);
    printf("Insert Position for %d in Stack A: %d\n", median, insert_position);

    // Test: Calculate rotations
    printf("Rotations in A for Position %d: %d\n", insert_position, calc_rotations_for_a(stack_a, insert_position));

    if (stack_b->size > 0) // Only test if Stack B has elements
    {
        printf("Rotations in B for Position %d: %d\n", 0, calc_rotations_for_b(stack_b, 0));
    }

    // Test: Partition stack based on median
    partition_stack(stack_a, stack_b, median, stack_a->size);
    print_stack_state("After Partition", stack_a, stack_b);

    // Test: Sort small stack (sort_three)
    if (stack_a->size == 3)
    {
        sort_three(stack_a);
        print_stack_state("After Sort Three", stack_a, stack_b);
    }

    // Test: Sort five elements (sort_five)
    if (stack_a->size == 5)
    {
        sort_five(stack_a, stack_b);
        print_stack_state("After Sort Five", stack_a, stack_b);
    }

    // Test: Quick median sort for larger stacks
    if (stack_a->size > 5)
    {
        quick_median_sort(stack_a, stack_b);
        print_stack_state("After Quick Median Sort", stack_a, stack_b);
    }

    // Test: Move with minimal cost
    if (stack_b->size > 0)
    {
        int target_value = stack_b->top->value;
        move_with_min_cost(stack_a, stack_b, target_value);
        print_stack_state("After Moving with Minimal Cost", stack_a, stack_b);
    }

    // Free resources
    free_stack(stack_a);
    free_stack(stack_b);

    return (EXIT_SUCCESS);
}


// Prints the state of the stacks (minimal debug version)
void print_stack_state(const char *msg, t_stack *stack_a, t_stack *stack_b)
{
    printf("\n%s\n", msg);
    if (stack_a)
    {
        printf("Stack A: [Size: %d]\n", stack_a->size);
        t_node *current = stack_a->top;
        while (current)
        {
            printf("%d ", current->value);
            current = current->next;
        }
        printf("\n");
    }
    else
        printf("Stack A: NULL\n");

    if (stack_b)
    {
        printf("Stack B: [Size: %d]\n", stack_b->size);
        t_node *current = stack_b->top;
        while (current)
        {
            printf("%d ", current->value);
            current = current->next;
        }
        printf("\n");
    }
    else
        printf("Stack B: NULL\n");
}

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    int median;
    int smallest_value, insert_position;

    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <numbers>\n", argv[0]);
        return (EXIT_FAILURE);
    }

    // Initialize stacks
    stack_a = parse_arguments(argc, argv);
    stack_b = init_stack();

    if (!stack_a || !stack_b)
    {
        fprintf(stderr, "Error: Stack initialization failed\n");
        free_stack(stack_a);
        free_stack(stack_b);
        return (EXIT_FAILURE);
    }

    print_stack_state("Initial Stacks", stack_a, stack_b);

    // Test find_median
    median = find_median(stack_a);
    printf("Median: %d\n", median);

    // Test get_smallest
    smallest_value = get_smallest(stack_a);
    printf("Smallest Value in Stack A: %d\n", smallest_value);

    // Test get_position
    printf("Position of %d in Stack A: %d\n", smallest_value, get_position(stack_a, smallest_value));

    // Test get_insert_position
    insert_position = get_insert_position(stack_a, median);
    printf("Insert Position for %d in Stack A: %d\n", median, insert_position);

    // Test calc_rotations_for_a and calc_rotations_for_b
    printf("Rotations in A for Position %d: %d\n", insert_position, calc_rotations_for_a(stack_a, insert_position));

    if (stack_b->size > 0) // Only test if Stack B has elements
    {
        printf("Rotations in B for Position %d: %d\n", 0, calc_rotations_for_b(stack_b, 0));
    }

    // Partition the stack based on the median
    partition_stack(stack_a, stack_b, median, stack_a->size);

    print_stack_state("After Partition", stack_a, stack_b);

    // Free resources
    free_stack(stack_a);
    free_stack(stack_b);

    return (EXIT_SUCCESS);
}

// Prints the state of the stacks (minimal debug version)
void print_stack_state(const char *msg, t_stack *stack_a, t_stack *stack_b)
{
    printf("\n%s\n", msg);
    if (stack_a)
        printf("Stack A: [Size: %d]\n", stack_a->size);
    else
        printf("Stack A: NULL\n");

    if (stack_b)
        printf("Stack B: [Size: %d]\n", stack_b->size);
    else
        printf("Stack B: NULL\n");
}

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    int median;

    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <numbers>\n", argv[0]);
        return (EXIT_FAILURE);
    }

    // Initialize stacks
    stack_a = parse_arguments(argc, argv);
    stack_b = init_stack();

    if (!stack_a || !stack_b)
    {
        fprintf(stderr, "Error: Stack initialization failed\n");
        return (EXIT_FAILURE);
    }

    print_stack_state("Initial Stacks", stack_a, stack_b);

    // Find median and partition stack
    median = find_median(stack_a);
    printf("Median: %d\n", median);

    partition_stack(stack_a, stack_b, median, stack_a->size);

    print_stack_state("After Partition", stack_a, stack_b);

    // Free resources
    free_stack(stack_a);
    free_stack(stack_b);

    return (EXIT_SUCCESS);
}

// Prints the current state of the stacks (simplified version)
void print_stack_state(const char *msg, t_stack *stack_a, t_stack *stack_b)
{
    t_node *current;

    printf("\n%s\n", msg);

    if (stack_a)
    {
        printf("Stack A: ");
        current = stack_a->top;
        while (current)
        {
            printf("%d ", current->value);
            current = current->next;
        }
        printf("\n");
    }
    else
        printf("Stack A is NULL\n");

    if (stack_b)
    {
        printf("Stack B: ");
        current = stack_b->top;
        while (current)
        {
            printf("%d ", current->value);
            current = current->next;
        }
        printf("\n");
    }
    else
        printf("Stack B is NULL\n");
}

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    int median;

    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <numbers>\n", argv[0]);
        return (EXIT_FAILURE);
    }

    // Initialize stacks
    stack_a = parse_arguments(argc, argv);
    stack_b = init_stack();

    if (!stack_a || !stack_b)
    {
        fprintf(stderr, "Error: Stack initialization failed\n");
        return (EXIT_FAILURE);
    }

    print_stack_state("Initial Stack States", stack_a, stack_b);

    // Find median and partition stack
    median = find_median(stack_a);
    printf("Median: %d\n", median);

    partition_stack(stack_a, stack_b, median, stack_a->size);

    print_stack_state("After Partition", stack_a, stack_b);

    // Free stacks
    free_stack(stack_a);
    free_stack(stack_b);

    return (EXIT_SUCCESS);
}


void print_stack_state(const char *msg, t_stack *stack_a, t_stack *stack_b)
{
    t_node *current;

    printf("\n%s\n", msg);

    if (stack_a)
    {
        printf("Stack A (size=%d): ", stack_a->size);
        current = stack_a->top;
        while (current)
        {
            printf("%d(prev=%p, next=%p) ", current->value, (void *)current->prev, (void *)current->next);
            current = current->next;
        }
        printf("\n");
    }
    else
        printf("Stack A is NULL\n");

    if (stack_b)
    {
        printf("Stack B (size=%d): ", stack_b->size);
        current = stack_b->top;
        while (current)
        {
            printf("%d(prev=%p, next=%p) ", current->value, (void *)current->prev, (void *)current->next);
            current = current->next;
        }
        printf("\n");
    }
    else
        printf("Stack B is NULL\n");
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <numbers>\n", argv[0]);
        return (EXIT_FAILURE);
    }

    // Use parse_arguments to initialize stack_a
    t_stack *stack_a = parse_arguments(argc, argv);
    if (!stack_a)
    {
        fprintf(stderr, "Error: Invalid input\n");
        return (EXIT_FAILURE);
    }

    t_stack *stack_b = init_stack();
    if (!stack_b)
    {
        fprintf(stderr, "Error: Failed to initialize stack_b\n");
        free_stack(stack_a);
        return (EXIT_FAILURE);
    }

    print_stack_state("Initial Stack States", stack_a, stack_b);

    if (stack_a->size <= 3)
    {
        printf("Sorting stack with sort_three...\n");
        sort_three(stack_a);
    }
    else if (stack_a->size <= 5)
    {
        printf("Sorting stack with sort_five...\n");
        sort_five(stack_a, stack_b);
    }
    else
    {
        printf("Stack size too large for small sort functions\n");
    }

    print_stack_state("Final Stack States", stack_a, stack_b);

    free_stack(stack_a);
    free_stack(stack_b);

    return (EXIT_SUCCESS);
}


t_stack *initialize_stack_from_args(int ac, char **av)
{
    t_stack *stack = init_stack();
    if (!stack)
    {
        fprintf(stderr, "Error: Failed to initialize stack\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i < ac; i++)
    {
        char *endptr;
        int value = strtol(av[i], &endptr, 10);
        if (*endptr != '\0') // Check for non-numeric characters
        {
            fprintf(stderr, "Error: Invalid input '%s'\n", av[i]);
            free_stack(stack); // Free already allocated resources
            exit(EXIT_FAILURE);
        }
        push_bottom(stack, value);
    }

    return stack;
}

void print_stack_state(const char *msg, t_stack *stack_a, t_stack *stack_b)
{
    t_node *current;

    printf("\n%s\n", msg);

    if (stack_a)
    {
        printf("Stack A (size=%d): ", stack_a->size);
        current = stack_a->top;
        while (current)
        {
            printf("%d(prev=%p, next=%p) ", current->value, (void *)current->prev, (void *)current->next);
            current = current->next;
        }
        printf("\n");
    }
    else
        printf("Stack A is NULL\n");

    if (stack_b)
    {
        printf("Stack B (size=%d): ", stack_b->size);
        current = stack_b->top;
        while (current)
        {
            printf("%d(prev=%p, next=%p) ", current->value, (void *)current->prev, (void *)current->next);
            current = current->next;
        }
        printf("\n");
    }
    else
        printf("Stack B is NULL\n");
}

int main(int ac, char **av)
{
    if (ac < 2)
    {
        fprintf(stderr, "Usage: %s <numbers>\n", av[0]);
        return (EXIT_FAILURE);
    }

    t_stack *stack_a = initialize_stack_from_args(ac, av);
    t_stack *stack_b = init_stack();

    if (!stack_a || !stack_b)
    {
        fprintf(stderr, "Error: Stack initialization failed\n");
        return (EXIT_FAILURE);
    }

    print_stack_state("Initial Stack States", stack_a, stack_b);

    if (stack_a->size <= 3)
    {
        printf("Sorting stack with sort_three...\n");
        sort_three(stack_a);
    }
    else if (stack_a->size <= 5)
    {
        printf("Sorting stack with sort_five...\n");
        sort_five(stack_a, stack_b);
    }
    else
    {
        printf("Stack size too large for small sort functions\n");
    }

    print_stack_state("Final Stack States", stack_a, stack_b);

    free_stack(stack_a);
    free_stack(stack_b);

    return (EXIT_SUCCESS);
}


int main(void)
{
    t_stack *stack_a;
    t_stack *stack_b;

    // Initialize stacks
    stack_a = init_stack();
    stack_b = init_stack();

    if (!stack_a || !stack_b)
    {
        fprintf(stderr, "Error: Failed to initialize stacks\n");
        return (1);
    }

    // Populate stack_a
    push_bottom(stack_a, 5);
    push_bottom(stack_a, 3);
    push_bottom(stack_a, 8);
    push_bottom(stack_a, 1);
    push_bottom(stack_a, 7);

    print_stack_state("Initial Stack States", stack_a, stack_b);

    // Perform operations and print the stack state after each
    sa(stack_a);
    print_stack_state("After sa (swap stack_a)", stack_a, stack_b);

    pb(stack_a, stack_b);
    print_stack_state("After pb (push top of stack_a to stack_b)", stack_a, stack_b);

    ra(stack_a);
    print_stack_state("After ra (rotate stack_a)", stack_a, stack_b);

    rb(stack_b);
    print_stack_state("After rb (rotate stack_b)", stack_a, stack_b);

    pa(stack_b, stack_a);
    print_stack_state("After pa (push top of stack_b to stack_a)", stack_a, stack_b);

    rra(stack_a);
    print_stack_state("After rra (reverse rotate stack_a)", stack_a, stack_b);

    rr(stack_a, stack_b);
    print_stack_state("After rr (rotate both stacks)", stack_a, stack_b);

    rrr(stack_a, stack_b);
    print_stack_state("After rrr (reverse rotate both stacks)", stack_a, stack_b);

    // Free stacks
    free_stack(stack_a);
    free_stack(stack_b);

    return (0);
}



int main(void)
{
    t_stack *stack_a;
    t_stack *stack_b;

    // Initialize stacks
    stack_a = init_stack();
    stack_b = init_stack();

    if (!stack_a || !stack_b)
    {
        fprintf(stderr, "Error: Failed to initialize stacks\n");
        return (1);
    }

    // Populate stack_a
    push_bottom(stack_a, 5);
    push_bottom(stack_a, 3);
    push_bottom(stack_a, 8);
    push_bottom(stack_a, 1);
    push_bottom(stack_a, 7);

    printf("Initial Stack States:\n");
    print_stack_state(stack_a, stack_b);

    // Perform operations and print the stack state after each
    printf("Performing sa (swap stack_a)...\n");
    sa(stack_a);
    print_stack_state(stack_a, stack_b);

    printf("Performing pb (push top of stack_a to stack_b)...\n");
    pb(stack_a, stack_b);
    print_stack_state(stack_a, stack_b);

    printf("Performing ra (rotate stack_a)...\n");
    ra(stack_a);
    print_stack_state(stack_a, stack_b);

    printf("Performing rb (rotate stack_b)...\n");
    rb(stack_b);
    print_stack_state(stack_a, stack_b);

    printf("Performing pa (push top of stack_b to stack_a)...\n");
    pa(stack_b, stack_a);
    print_stack_state(stack_a, stack_b);

    printf("Performing rra (reverse rotate stack_a)...\n");
    rra(stack_a);
    print_stack_state(stack_a, stack_b);

    printf("Performing rr (rotate both stacks)...\n");
    rr(stack_a, stack_b);
    print_stack_state(stack_a, stack_b);

    printf("Performing rrr (reverse rotate both stacks)...\n");
    rrr(stack_a, stack_b);
    print_stack_state(stack_a, stack_b);

    // Free stacks
    free_stack(stack_a);
    free_stack(stack_b);

    return (0);
}

void	print_stack_state(t_stack *stack_a, t_stack *stack_b)
{
    t_node *current;

    printf("Stack A: ");
    current = stack_a->top;
    while (current)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");

    printf("Stack B: ");
    current = stack_b->top;
    while (current)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

int	main(void)
{
	t_stack *stack_a;
	t_stack *stack_b;

	// Initialize stacks
	stack_a = init_stack();
	stack_b = init_stack();

	if (!stack_a || !stack_b)
	{
		printf("Failed to initialize stacks\n");
		return (1);
	}

	// Populate stack_a
	push_bottom(stack_a, 5);
	push_bottom(stack_a, 3);
	push_bottom(stack_a, 8);
	push_bottom(stack_a, 1);
	push_bottom(stack_a, 7);

	// Print initial stack state
	print_stack_state(stack_a, stack_b);

	// Perform operations and print the stack state after each
	sa(stack_a);  // Swap top two elements
	print_stack_state(stack_a, stack_b);

	pb(stack_a, stack_b); // Push top element from A to B
	print_stack_state(stack_a, stack_b);

	ra(stack_a);  // Rotate A
	print_stack_state(stack_a, stack_b);

	rb(stack_b);  // Rotate B
	print_stack_state(stack_a, stack_b);

	pa(stack_b, stack_a); // Push top element from B to A
	print_stack_state(stack_a, stack_b);

	rra(stack_a); // Reverse rotate A
	print_stack_state(stack_a, stack_b);

	rr(stack_a, stack_b); // Rotate both A and B
	print_stack_state(stack_a, stack_b);

	rrr(stack_a, stack_b); // Reverse rotate both A and B
	print_stack_state(stack_a, stack_b);

	// Free stacks
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}

int	main(void)
{
	t_stack *stack;

	// Initialize the stack
	stack = init_stack();
	if (!stack)
	{
		printf("Failed to initialize stack\n");
		return (1);
	}

	// Add values to the stack
	push_bottom(stack, 5);
	push_bottom(stack, 3);
	push_bottom(stack, 8);
	push_bottom(stack, 1);
	push_bottom(stack, 7);

	// Test is_sorted
	printf("Is stack sorted? %s\n", is_sorted(stack) ? "Yes" : "No");

	// Test get_smallest
	printf("Smallest value in stack: %d\n", get_smallest(stack));

	// Test get_position
	int value = 3;
	printf("Position of %d in stack: %d\n", value, get_position(stack, value));

	// Print all stack values for debugging
	t_node *current = stack->top;
	printf("Stack contents (top to bottom): ");
	while (current)
	{
		printf("%d ", current->value);
		current = current->next;
	}
	printf("\n");

	// Free the stack
	free_stack(stack);
	return (0);
}

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
*/