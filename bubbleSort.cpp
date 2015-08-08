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

int buggleSort(int A[], int N){
  bool flag = true;
  int j;
  int temp = 0;
  int swapCount = 0;
  int underSort = 0;
  while(flag){
    flag = false;
    for(j = N-1; underSort + 1 <= j ; j--){
      if(A[j] < A[j-1]){
        swap(&A[j], &A[j - 1]);
        flag = true;
        swapCount++;
      }
    }
    underSort++;
  }

  //trace(A, N);
  return swapCount;
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
  A = (int *)calloc(N, sizeof(N));

  for( i = 0; i < N; i++ ){
    fscanf(fp, "%d", &A[i]);
  }

  //trace(A, N);
  clock_t start = clock();
  swapCount = buggleSort(A, N);
  clock_t end = clock();

  double resultTime = (double)(end - start)/CLOCKS_PER_SEC;

  printf("%d,%f\n", N, resultTime);  
  //printf("%d\n", swapCount);
  return 0;
}
