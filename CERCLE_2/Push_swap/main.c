
#include "push_swap.h"
#include <stdio.h> 

int main(int ac, char **av)
{
    t_stack *stack_a;
    t_stack *stack_b;
    int i;
    int value;

    if (ac < 2)
    {
        ft_putstr_fd("Usage: ./push_swap <numbers>\n", 2);
        return 1;
    }

    stack_a = init_stack();
    stack_b = init_stack();

    // Populate stack_a from command-line arguments
    i = 1;
    while (i < ac)
    {
        if (!ft_atoi_safe(av[i], &value))
        {
            ft_putstr_fd("Error\n", 2);
            free_stack(stack_a);
            free_stack(stack_b);
            return 1;
        }
        push_bottom(stack_a, value); // Add to the stack
        i++;
    }

    printf("Before sorting:\n");
    print_stack(stack_a);

    radix_sort(stack_a, stack_b);

    printf("After sorting:\n");
    print_stack(stack_a);

    free_stack(stack_a);
    free_stack(stack_b);

    return 0;
}

/*int main(void)
{
    t_stack *stack_a = init_stack();
    t_stack *stack_b = init_stack();

    // Test Case: Large numbers
    push_bottom(stack_a, 100000);
    push_bottom(stack_a, 20000);
    push_bottom(stack_a, 50000);
    push_bottom(stack_a, 30000);
    push_bottom(stack_a, 40000);

    printf("Before sorting:\n");
    print_stack(stack_a);

    radix_sort(stack_a, stack_b);

    printf("After sorting:\n");
    print_stack(stack_a);

    free_stack(stack_a);
    free_stack(stack_b);

    return 0;
}


int main(void)
{
    t_stack *stack_a = init_stack();
    t_stack *stack_b = init_stack();

    // Test Case: 5 elements
    push_bottom(stack_a, 3);
    push_bottom(stack_a, 5);
    push_bottom(stack_a, 1);
    push_bottom(stack_a, 4);
    push_bottom(stack_a, 2);

    printf("Before sorting:\n");
    print_stack(stack_a);

    sort_five(stack_a, stack_b);

    printf("After sorting:\n");
    print_stack(stack_a);

    return 0;
}
*/