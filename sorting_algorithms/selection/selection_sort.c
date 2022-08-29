#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Global variable
int num_arr[20];

// Defines the size of the array
int size = sizeof(num_arr) / sizeof(num_arr[0]);

/*  Prototypes */
void random_array();
int selection_sort(int arr[]);
void swap(int *previous, int *next);
void print_array();
/*  End of prototypes */

/*  Main function start */
int main(void)
{
    // Produces an array of integers randomly populated
    random_array();
    print_array();
    selection_sort(num_arr);
    print_array();
}
/*  Main function end */

/*  Function implementation*/
void random_array()
{
    // Seeds the rand() call to display different numbers when called
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        num_arr[i] = rand() % 100;
    }
}

int selection_sort(int arr[])
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            // For descending order, change ">" for "<"
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        swap(&arr[min], &arr[i]);
    }

    return 0;
}

void swap(int *previous, int *next)
{
    int temp = *previous;
    *previous = *next;
    *next = temp;
}

void print_array()
{
    for (int i = 0; i < size; i++)
    {
        // Last element
        if (i == size - 1)
        {
            printf("%d\n", num_arr[i]);
        }
        // Any other element
        else
        {
            printf("%d, ", num_arr[i]);
        }
    }
}
/*  End of function implementation */