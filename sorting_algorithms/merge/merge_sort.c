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
int merge_sort(int arr[], int left, int right);
void merge_sorted_arrays(int arr[], int left, int middle, int right);
void swap(int *previous, int *next);
void print_array();
/*  End of prototypes */

/*  Main function start */
int main(void)
{
    // Produces an array of integers randomly populated
    random_array();
    print_array();

    // "0" is the left-most index and "size - 1" is the right-most index
    merge_sort(num_arr, 0, size - 1);
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

int merge_sort(int arr[], int left, int right)
{
    //  Stops recursion when left >= right
    if (left < right)
    {
        // Finds the midpoint of left and right
        int middle = left + (right - left) / 2;

        // Calls the function recursively
        merge_sort(arr, left, middle);
        merge_sort(arr, middle + 1, right);
        merge_sorted_arrays(arr, left, middle, right);
    }
    return 0;
}

void merge_sorted_arrays(int arr[], int left, int middle, int right)
{
    // Gets the length of the right/left arrays
    int left_size = middle - left + 1;
    int right_size = right - middle;

    // Create temporary arrays to hold each half
    int left_array[left_size];
    int right_array[right_size];

    // Merges the left part into the array
    for (int i = 0; i < left_size; i++)
    {
        left_array[i] = arr[left + i];
    }

    // Merges the right part into the array
    for (int i = 0; i < right_size; i++)
    {
        right_array[i] = arr[middle + 1 + i];
    }
    for (int i = 0, j = 0, k = left; k <= right; k++)
    {
        if ((i < left_size) &&
            (j >= right_size || left_array[i] <= right_array[j]))
        {
            arr[k] = left_array[i];
            i++;
        }
        else
        {
            arr[k] = right_array[j];
            j++;
        }
    }
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