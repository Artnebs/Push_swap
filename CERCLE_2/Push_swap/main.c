
#include "push_swap.h"
#include <stdio.h> // For testing

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
