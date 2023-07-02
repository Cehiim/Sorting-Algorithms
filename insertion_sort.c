void *insertionSort(int *v, int key, int end){
  if(key < end){
    while(v[key-1] > v[key]){
      swap(v, key-1, key);
      showChart(v, end);
      key -= 1;
    }
  insertionSort(v, key+1, end);
  }
}
