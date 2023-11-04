int partition(int *v, int start, int end, int size){
  int pivot = v[start], i = start;
  for(int j = start+1; j <= end; j++){
    if(v[j] < pivot){
      i++;
      swap(v, i, j);
      showChart(v, size);
    }
  }
  swap(v,start,i);
  showChart(v, size);
  return i;
}

void quickSort(int *v, int start, int end, int size){
  if(start < end){
    int pivot_i = partition(v, start, end, size);
    quickSort(v, start, pivot_i-1, size);
    quickSort(v, pivot_i+1, end, size);
  }
}
