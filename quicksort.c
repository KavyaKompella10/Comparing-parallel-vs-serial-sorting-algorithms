#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#define N 10

// function for swapping
void swapping(int i, int j, int *arr) {
  int c = *(arr+i);
  *(arr+i) = *(arr+j);
  *(arr+j) = c;
}

//This function return index of the partition
int partition(int* arr, int low, int high) {
  
  int pivot = arr[high]; // declaring pivot as the last element in the array (element of highest index)
  int j,i = (low - 1);


  for (j = low; j < high; j++) {
    if (arr[j] <= pivot) {
      i++;
      swapping(i, j, arr);
    }
  }
//  swapping(&arr[i + 1], &arr[high]);
swapping(i+1,high, arr);
  
 
  return (i + 1);
}


void quickSort(int *arr, int low, int high) {
  if (low < high) {
    
    int pi = partition(arr, low, high);
  
    quickSort(arr, low, pi - 1);
  
    quickSort(arr, pi + 1, high);
  }
}


void printArray(int arr[], int length) {
	int i;
  for ( i = 0; i < length; ++i) {
    printf("%d  ", arr[i]);
  }
  printf("\n");
}


int main(int argc, char **argv) {

int i,n=N;
int *array;
clock_t t;
    t = clock();
    printf("before malloc \n");
 array = (int*)malloc(n * sizeof(int));
 printf("after allocATION\n");
  	for(i = 0; i < n; i++)
	{	
//		temp = array + i;
		array[i] = rand()%10;
	}
	printf("After instansiating \n");
  printf("Unsorted arr\n");
  printArray(array, n);
  

  quickSort(array, 0, n - 1);
   t = clock() - t;
   printf("Sorted arr in ascending order: \n");
  printArray(array, n);
    printf("After \n");
	printf("\n elaspsed = %f  seconds \n", ((double)t)/CLOCKS_PER_SEC);
	free(array);
  return 0;
  
}
