#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void traceH(int A[], int N){
  int i;
  for( i = 0; i < N; i++){
    if( i > 0 )printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
}

void traceV(int A[], int N){
  int i;
  for( i = 0; i < N; i++){
    printf("%d\n", A[i]);
  }
}

void traceOutput(int* A, int N, int m, int* G, int cnt){
  printf("%d\n", m);
  traceH(G, m);
  printf("%d\n", cnt);
  traceV(A, N);
}

void swap(int* arg1, int* arg2){
  int work;

  work = *arg1;
  *arg1 = *arg2;
  *arg2 = work;
}

int insertionSort(int* A, int n, int g){
  int i, v, j, cnt = 0;

  for(i = g; i <= n - 1; i++){
    v = A[i];
    j = i - g;
    while( j >= 0 && A[j] > v){
      A[j+g] = A[j];
      j = j - g;
      cnt++;
    }
    A[j+g] = v;
  }

  return cnt;
}

void shellSort(int* A, int n){
  int cnt = 0;
  int m = 3;
  int G[] = {4,3,1};
  for(int i = 0; i <= m - 1; i++){
    cnt += insertionSort(A, n, G[i]);
  }

  //traceOutput(A, n, m, G, cnt);
}

int main(){
  int N, i, j;
  //int A[1000];
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

  clock_t start = clock();
  shellSort(A, N);
  clock_t end = clock();
  double resultTime = (double)(end - start)/CLOCKS_PER_SEC;

  printf("%d,%f\n", N, resultTime);

  return 0;
}
