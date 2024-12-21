#include "push_swap.h"

/* Determine the number of chunks based on the stack size */
static int get_chunk_count(int size)
{
    if (size <= 100)
        return (5);
    return (11);
}

/* Count how many elements are within a chunk's range */
static int count_in_chunk(t_stack *stack_a, int min_range, int max_range)
{
    t_node *current_node;
    int count;

    current_node = stack_a->top;
    count = 0;
    while (current_node)
    {
        if (current_node->value >= min_range && current_node->value <= max_range)
            count++;
        current_node = current_node->next;
    }
    return (count);
}

/* Apply chunk-based sorting by dividing the stack into chunks */
static void apply_chunks(t_stack *stack_a, t_stack *stack_b, int size)
{
    int chunks;
    int chunk_size;
    int i;
    int min_range;
    int max_range;
    int count;

    chunks = get_chunk_count(size);
    chunk_size = size / chunks;
    i = 0;
    while (i < chunks)
    {
        min_range = i * chunk_size;
        max_range = (i == chunks - 1) ? size - 1 : (i + 1) * chunk_size - 1;
        count = count_in_chunk(stack_a, min_range, max_range);
        while (count > 0)
        {
            if (stack_a->top->value >= min_range && stack_a->top->value <= max_range)
            {
                pb(stack_a, stack_b);
                count--;
            }
            else
                ra(stack_a);
        }
        i++;
    }
}

/* Get the smallest value in stack a */
static int get_smallest_value(t_stack *stack_a)
{
    t_node *current_node;
    int smallest;

    current_node = stack_a->top;
    smallest = current_node->value;
    while (current_node)
    {
        if (current_node->value < smallest)
            smallest = current_node->value;
        current_node = current_node->next;
    }
    return (smallest);
}

/* Get the position of a specific value in stack a */
static int get_position_value(t_stack *stack_a, int value)
{
    t_node *current_node;
    int position;

    current_node = stack_a->top;
    position = 0;
    while (current_node)
    {
        if (current_node->value == value)
            return (position);
        position++;
        current_node = current_node->next;
    }
    return (-1);
}

/* Push Swap Algorithm */
void push_swap(t_stack *stack_a, t_stack *stack_b)
{
    int size;
    int smallest_value;
    int position;

    size = stack_a->size;
    if (is_sorted(stack_a))
        return;

    if (size <= 3)
    {
        sort_three(stack_a);
        return;
    }
    if (size <= 5)
    {
        sort_five(stack_a, stack_b);
        return;
    }
    if (size > 200)
    {
        sort_large(stack_a, stack_b); // Use Radix Sort for large datasets
        return;
    }

    apply_chunks(stack_a, stack_b, size);

    while (stack_b->size > 0)
        move_with_min_cost(stack_a, stack_b, stack_b->top->value);

    if (!is_sorted(stack_a))
    {
        smallest_value = get_smallest_value(stack_a);
        position = get_position_value(stack_a, smallest_value);
        if (position >= 0)
        {
            if (position <= stack_a->size / 2)
                while (position-- > 0)
                    ra(stack_a);
            else
                while (position++ < stack_a->size)
                    rra(stack_a);
        }
    }
}
