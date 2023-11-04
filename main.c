int main(void) {
  int *v, n = 9;
  bool exit = false;
  srand (time(NULL));
  v = getArray(n);
  while(!exit){
    struct timespec start_time, end_time;
    double elapsed_time;
    int *cpy, option, ok = 0;
    cpy = copyArray(v, n);
    showChart(cpy, n);
    puts("0. Change number of elements");
    puts("1. Bubble sort");
    puts("2. Insertion sort");
    puts("3. Selection sort");
    puts("4. Shell sort");
    puts("5. Quick sort");
    puts("6. Merge sort");
    puts("7. Heap sort");
    puts("8. Exit");
    scanf("%i", &option);
    switch(option){
      case 0:
        puts("");
        printf("Number of elements: ");
        int new_n;
        scanf("%i", &new_n);
        if(new_n > 1 && new_n <= 50){
          n = new_n;
          v = getArray(n);
          puts("Elements updated");
        }
        else{
          puts("Invalid number");
        }
        break;
      case 1:
        puts("--> Bubble sort");
        clock_gettime(CLOCK_MONOTONIC, &start_time);
        bubbleSort(cpy, 1, n);
        clock_gettime(CLOCK_MONOTONIC, &end_time);
        confirm(&start_time,&end_time);
        break;
      case 2:
        puts("--> Insertion sort");
        clock_gettime(CLOCK_MONOTONIC, &start_time);
        insertionSort(cpy, 1, n);
        clock_gettime(CLOCK_MONOTONIC, &end_time);
        confirm(&start_time,&end_time);
        break;
      case 3:
        puts("--> Selection sort");
        clock_gettime(CLOCK_MONOTONIC, &start_time);
        selectionSort(cpy, 0, n);
        clock_gettime(CLOCK_MONOTONIC, &end_time);
        confirm(&start_time,&end_time);
        break;
      case 4:
        puts("--> Shell sort");
        clock_gettime(CLOCK_MONOTONIC, &start_time);
        shellSort(cpy, n/2, n);
        clock_gettime(CLOCK_MONOTONIC, &end_time);
        confirm(&start_time,&end_time);
        break;
      case 5:
        puts("--> Quick sort");
        clock_gettime(CLOCK_MONOTONIC, &start_time);
        quickSort(cpy, 0, n-1, n);
        clock_gettime(CLOCK_MONOTONIC, &end_time);
        confirm(&start_time,&end_time);
        break;
      case 6:
        puts("--> Merge sort");
        break;
      case 7:
        puts("--> Heap sort");
        break;
      case 8:
        exit = true;
        printf("\033c");
        puts("Program has been ended");
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
