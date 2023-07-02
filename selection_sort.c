void *selectionSort(int *v, int min, int end){
  if(min < end-1){
    for(int x = min+1; x < end; x++){
      if(v[min] > v[x]){
      swap(v, min, x);
      showChart(v, end);
      }
    }
    selectionSort(v, min+1, end);
  }
}
