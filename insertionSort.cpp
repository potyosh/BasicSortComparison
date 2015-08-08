#include<stdio.h>
#include <stdlib.h>
#include <time.h>

void trace(int A[], int N){
  int i;
  for( i = 0; i < N; i++){
    printf("%d\n", A[i]);
  }
  printf("\n");
}

void insertionSort(int A[], int N){
  int j, i, v;
  for( i = 1; i < N; i++ ){
    v = A[i];
    j = i - 1;
    while( j >= 0 && A[j] > v ){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
  }
  //trace(A, N);
}

int main(){
  int N, i, j;
  //int A[1000];
  int* A;
  FILE *fp;

  fp = fopen("test.txt", "r");
  fscanf(fp, "%d", &N);

  //メモリ確保
  A = (int *)calloc(N, sizeof(N));

  for( i = 0; i < N; i++ ){
    fscanf(fp, "%d", &A[i]);
  }

  clock_t start = clock();
  insertionSort(A, N);
  clock_t end = clock();
  double resultTime = (double)(end - start)/CLOCKS_PER_SEC;

  printf("%d,%f\n", N, resultTime);
  return 0;
}
