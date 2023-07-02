int main(void) {
  int *v, n = 9, end = 0; // It is recomended to keep the 'n' value smaller than 10, otherwise it can mess up the chart visualization
  srand (time(NULL)); // Get a random seed for every run, therefore the array will be always different
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
