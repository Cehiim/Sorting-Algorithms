int isRepeated(int *v, int end, int n){
  for(int x = 0; x < end; x++){
    if(v[x] == n){
      return 1;
    }
  }
  return 0;
}

int getArray(int size){
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

int copyArray(int *v, int size){
  int *cpy;
  cpy = (int*)calloc(size, sizeof(int));
  for(int x = 0; x < size; x++){
    cpy[x] = v[x];
  }
  return cpy;
}

void showArray(int *v, int size){
  for(int x = 0; x < size; x++){
    printf("%i ",v[x]);
  }
  puts("\n");
}

void showChart(int *v, int size){
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

void *swap(int *v, int pos1, int pos2){
  int aux = v[pos2];
  v[pos2] = v[pos1];
  v[pos1] = aux;
}

void confirm(){
  int ok = 0;
  while(ok == 0){
    puts("Press 1 to continue");
    scanf("%i", &ok);
  }
}
