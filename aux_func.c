#include <stdio.h> // Input and output
#include <stdlib.h> // Memory manageament and random function
#include <unistd.h> // Sleep function
#include <time.h> // Time function to generate random seeds

int isRepeated(int *v, int end, int n){ // Check if a number is already in an array, return 1 if it is or 0 if it is not
  for(int x = 0; x < end; x++){
    if(v[x] == n){
      return 1;
    }
  }
  return 0;
}

int getArray(int size){ // Return an array with random numbers in
  int *v;
  v = (int*)calloc(size, sizeof(int));
  for(int x = 0; x < size; x++){
    int num = rand() % size+1;
    if(x > 0 && isRepeated(v, size, num) == 1){
      x -= 1;
    }
    else{
      v[x] = num;
    }
  }
  return v;
}

int copyArray(int *v, int size){ // Copy the numbers in a array to another
  int *cpy;
  cpy = (int*)calloc(size, sizeof(int));
  for(int x = 0; x < size; x++){
    cpy[x] = v[x];
  }
  return cpy;
}

void showArray(int *v, int size){ // Show the numbers in a array
  for(int x = 0; x < size; x++){
    printf("%i ",v[x]);
  }
  puts("\n");
}

void showChart(int *v, int size){ // Show a chart based on the numbers in a array
  usleep(1000 * 200);
  printf("\033c");
  for(int i = size; i > 0; i--){
    for(int j = 0; j < size; j++){
      if(v[j] >= i){
        printf("* ");
      }
      else{
        printf("  ");
      }
    }
    printf("\n");
  }
  if(size < 10){
    showArray(v, size);
  }
  else{
    puts("\n");
  }
}

void *swap(int *v, int pos1, int pos2){ // Swap the numbers of two positions
  int aux = v[pos2];
  v[pos2] = v[pos1];
  v[pos1] = aux;
}

void confirm(){ // Stop the program until the user confirms
  int ok = 0;
  while(ok == 0){
    puts("Continue?");
    scanf("%i", &ok);
  }
}
