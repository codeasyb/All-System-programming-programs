#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function prototype
void swap(int *arr, int i, int j);

//main function
int main(int argc, char *argv[])
{
     //declare the required variables
     int array[10];
     int maxIndex = 0, minIndex =0;
     int i = 0, j = 0, n = 2;

     //check whether the number of arguments are less than 2 or not
     if (argc < 2)
     {
          //print the error message
          printf("Data is insuffient! Please insert proper input at command line. \n");
     }
     else
     {   
          // read the integers from the command line
          for (i = 0; i < 10; i++)
              array[i] = atoi(argv[2 + i]);
     }

     printf("Selection sort on integer arrays \n\n");

     //print the elements that are read from the command line
     printf("Elements before sorting are: \n");

     //print the sorted elements
     for(i =0;i<10;i++)
          printf("%d ", array[i]);

     printf("\n");

     //check whether the first argument is -a, if
     //-a sort the elements in the array in asscending order
     if (strcmp(argv[1], "-a") == 0)
     {
          //logic to sort the elements in asscending order using selection sort
          for (i = 0; i < 10; ++i)
          {        
              minIndex = i;
              for (int j = i + 1; j < 10; ++j)
              {
                   if (array[j] < array[minIndex])
                        minIndex = j;
              }
              swap(array, minIndex, i);
          }
     }

     //check whether the first argument is -d, if
     //-d sort the elements in the array in descending order
     if (strcmp(argv[1], "-d") == 0)
     {   
          //logic to sort the elements in descending order using selection sort
          for (i = 0; i < 10; ++i)
          {
              maxIndex = i;
              for (j = i + 1; j < 10; ++j)
              {
                   if (array[j] > array[maxIndex])
                        maxIndex = j;
              }
              swap(array, maxIndex, i);
          }
     }

     //print the elements
     printf("\nElements after sorting are: \n");

     //print the sorted elements
     for(i =0;i<10;i++)
          printf("%d ", array[i]);

     printf("\n\n");

     return 0;
}

//definition of swap function
void swap(int *arr, int i, int j)
{
     int temp = arr[i];
     arr[i] = arr[j];
     arr[j] = temp;
}