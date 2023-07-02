void *bubbleSort(int *v, int start, int end){
  if(start < end-1){
    for(int x = 0; x < end-1; x++){
      if(v[x] > v[x+1]){
        swap(v, x, x+1);
        showChart(v, end);
      }
      bubbleSort(v, start+1, end);
    }
  }
}
