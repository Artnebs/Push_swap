#include "push_swap.h"

/**
 * Calculate the maximum number of bits required to represent the largest number
 * in the stack.
 */
static int get_max_bits(t_stack *stack_a)
{
    int max = stack_max_value(stack_a); // Find the largest value in the stack.
    int bits = 0;
    while ((max >> bits) != 0)
        bits++;
    return (bits);
}

/**
 * Radix Sort implementation for large datasets.
 */
void sort_large(t_stack *stack_a, t_stack *stack_b)
{
    int i, j;
    int size = stack_size(stack_a);
    int bits = get_max_bits(stack_a);

    i = 0;
    while (i < bits)
    {
        j = 0;
        while (j < size)
        {
            int top_val = stack_top_value(stack_a);
            if (((top_val >> i) & 1) == 0)
                pb(stack_a, stack_b); // Push to stack B if bit i is 0.
            else
                ra(stack_a); // Rotate stack A if bit i is 1.
            j++;
        }
        while (stack_size(stack_b) > 0)
            pa(stack_b, stack_a); // Push everything back to stack A.
        i++;
    }
}
