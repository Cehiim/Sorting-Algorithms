#include <stdio.h> // Input and output
#include <stdlib.h> // Memory manageament and random function
#include <unistd.h> // Sleep function
#include <time.h> // Time function to generate random seeds

int main(void) {
  int *v, n = 9, end = 0;
  srand (time(NULL));
  v = getArray(n);
  while(end == 0){
    int *cpy, sort, ok = 0;
    cpy = copyArray(v, n);
    showChart(cpy, n);
    puts("1. Bubble sort");
    puts("2. Insertion sort");
    puts("3. Selection sort");
    puts("4. Shell sort");
    puts("0. Exit");
    scanf("%i", &sort);
  
    switch(sort){
      case 0:
        end = 1;
        break;
      case 1:
        puts("--> Bubble sort");
        bubbleSort(cpy, 0, n);
        confirm();
        break;
      case 2:
        puts("--> Insertion sort");
        insertionSort(cpy, 1, n);
        confirm();
        break;
      case 3:
        puts("--> Selection sort");
        selectionSort(cpy, 0, n);
        confirm();
        break;
      case 4:
        puts("--> Shell sort");
        shellSort(cpy, n/2, n);
        confirm();
        break;
      default:
        puts("Invalid option, try again");
        break;
    }
    free(cpy);
  }
  free(v);
  return 0;
}
