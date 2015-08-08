#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void trace(int A[], int N){
  int i;
  for( i = 0; i < N; i++){
    if( i > 0 )printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
}

void swap(int* arg1, int* arg2){
  int work;

  work = *arg1;
  *arg1 = *arg2;
  *arg2 = work;
}

int selectionSort(int A[], int N){
  int i, j, minj;
  int swapCount = 0;

  for(i = 0; i <= N - 1; i++){
    minj = i;
    for(j = i + 1; j <= N - 1; j++){
      if(A[j] < A[minj]){
        minj = j;
      }
    }
    swap(&A[i], &A[minj]);
    //trace(A, N);
    if(i != minj)swapCount++;
  }

  return swapCount;
}

int main(){
  int N, i, j;
  //int A[100];
  int* A;
  int swapCount = 0;
  FILE *fp;

  fp = fopen("test.txt", "r");
  fscanf(fp, "%d", &N);

  //メモリ確保
  A = (int*)calloc(N, sizeof(int));

  for( i = 0; i < N; i++ ){
    fscanf(fp, "%d", &A[i]);
  }

  //trace(A, N);

  clock_t start = clock();
  swapCount = selectionSort(A, N);
  clock_t end = clock();

  double resultTime = (double)(end - start)/CLOCKS_PER_SEC;

  printf("%d,%f\n", N, resultTime);

  //printf("%d\n", swapCount);
  return 0;
}
