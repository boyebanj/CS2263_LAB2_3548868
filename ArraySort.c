/********************************
 * 
 * inPlaceSort.c
 * 
 * Assignment by Bridget Oyebanji
 * 
 * Task was to implement in place sorting using the two available functions
 * swapAdjacent, and compareAdjacent, and to find and fix bugs.
 * 
 ********************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printArray(int *array, int size)
{
    for(int i=0; i<size; i++)
    {
        if(i != 0)
        {
            printf(", ");
        }
        printf("%d", array[i]);
    }
    printf("\n");
}

void swapAdjacent(int *a, int index)
{    
    int temp = *(a + index);
    *(a + index) = *(a + index + 1);    
    *(a + index + 1) = temp;
}

int compareAdjacent(int *a, int index)
{
    return *(a + index) - *(a + index + 1);
}

/**
 * in place sorting on an array
 * by using the two functions swapAdjacent and compareAdjacent
 */
void inPlaceSort(int arr[], int n)
{
    int i, j;
    for(i = 0; i < n-1; i++)       
  
       // Last i elements in place already    
       for (j = 0; j < n-i-1; j++)  
           if ( compareAdjacent(arr, j) > 0 ){
              swapAdjacent(arr, j);
	   }
}

int main(void)
{

    int array_size = 0, i;
    printf("Enter the array size (>0) and the numbers to fill the array with: ");
    if(!scanf("%d", &array_size))
    {
        printf("ERROR. Must enter an integer.\n");
        return EXIT_FAILURE;
    }
    else if(array_size < 1)
    {
        printf("ERROR. array size must be at least 1.\n");
        return EXIT_FAILURE;
    }

    /**********************
     * filling the array with values
     **********************/

    int a[array_size];
     for (i = 0; i < array_size; ++i)
     {
        if(scanf("%d", &a[i]) != 1){
           printf("iNVALID INTEGER\n");
           return EXIT_FAILURE;
        }
     }
  
    
    printf("=== Array before Sorting = ");
    printArray(a, array_size);

    inPlaceSort(a, array_size);

    printf("=== Array after Sorting = ");
    printArray(a, array_size);

}

