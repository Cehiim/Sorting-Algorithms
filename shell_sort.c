void *shellSort(int *v, int gap, int end){
  if(gap > 0){
    for(int x = gap; x < end; x++){
      int aux = v[x], y = x;
      for(y; y >= gap; y -= gap){
        if(v[y-gap] > aux){
          v[y] = v[y-gap];
        }
        else{
          break;
        }
      }
      v[y] = aux;
      showChart(v, end);
    }
    shellSort(v, gap/2, end);
  }
}
