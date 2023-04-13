#include "search_algos.h"


/**
 * jump_search - searches for a value in a sorted linked list using a jump search
 * algorithm with an express lane, with a step size of sqrt(n)
 *
 * @list: pointer to the head of the linked list to search
 * @size: size of the linked list
 * @value: value to search for
 * Return: index of the first occurrence of the target value, or -1 if not found
 */
int jump_search(listint_t *list, size_t size, int value)
{
    int step = sqrt(size);
    listint_t *current = list;
    listint_t *prev = NULL;

    /* find the block containing the target value */
    while (current && current->n < value)
    {
        prev = current;
        int i;
        for (i = 0; current && i < step; i++)
            current = current->next;
    }

    /* perform linear search within the block */
    while (prev && prev->n < value)
        prev = prev->next;

    if (!prev || prev->n != value)
        return -1;

    return prev->index;
}


