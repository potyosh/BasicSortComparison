#include<stdio.h>
#include<time.h>
#include<stdlib.h>

/*乱数の最大値*/
//#define MAXRAND 1000

int main(void){
  /*乱数最大値*/
  int MAXRAND;
  /*乱数候補収納用変数*/
  int* iaRandarray;
  /*ループカウンタ用変数*/
  int iCounter;
  /*残り乱数候補数*/
  int iNumRand;
  /*乱数候補取得用変数*/
  int iRandKey;
  /*乱数の取得用変数*/
  int iRandVal;
  /*intから変換した文字列を入れるバッファ*/
  char* str;
  /*ファイル出力用ポインタ*/
  FILE *fp = fopen("test.txt", "w");


  /*乱数の種を初期化*/
  srand(time(NULL));

  /*標準入力からMAX取得*/
  scanf("%d", &MAXRAND);

  /*動的メモリ確保*/
  //A = (int *)calloc(N, sizeof(N));
  iaRandarray = (int*)calloc(MAXRAND, sizeof(int));
  str = (char*)calloc(MAXRAND, sizeof(char));

  /*あらかじめ配列に数値を代入しておく*/
  for( iCounter = 0 ; iCounter < MAXRAND ; ++iCounter){
    iaRandarray[iCounter] = iCounter + 1;
  }

  /* 総数出力toファイル */
  sprintf(str, "%d\n", MAXRAND);
  fputs(str, fp);

  /* 総数出力to標準出力 */
  //printf("%d\n", MAXRAND);

  /*テスト用ループ*/
  iNumRand = MAXRAND;
  for( iCounter = 0 ; iCounter < MAXRAND ; ++iCounter){

    /*乱数を取得*/
    iRandKey = rand();

    /*取得した乱数を残り配列で割った余りを取得する*/
    iRandKey %= iNumRand;

    /*配列の中身を乱数として取得する*/
    iRandVal = iaRandarray[ iRandKey ];

    /*つかった乱数を未使用の乱数で置き換える*/
    iaRandarray[ iRandKey ] = iaRandarray[ iNumRand - 1 ];

    /*乱数候補を一つ減らす*/
    --iNumRand;

    /*乱数の文字列変換*/
    sprintf(str, "%d\n", iRandVal);
    /*テスト用表示*/
    fputs(str, fp);
    //printf("%d\n",iRandVal);

  }

  fclose(fp);

}
