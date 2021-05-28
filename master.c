/* --------------------------------
file:       master.c
brief:      マスタ関係
ver:        1.0.0   
-------------------------------- */

/*インクルードファイル*/
#include "spi.h"
#include "timer.h"
#include "define.h"
#include "type.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*外部関数宣言*/
extern Data data;
extern U1 Simo(U1 *);
extern U1 Miso(U1 *);

/*プロトタイプ宣言*/
VP master(VP );
S4 SelectSlave(VD );

/*------------------------------*/
/* マスタ */
VP master(VP p_data){

    while(SelectSlave()){

        /*0111 1001*/
        U1 buff = 0x79; 
        /*データを送信 */
        Simo(&buff);
        /*データの受信*/
        //buff = Miso(NULL);
        Sleep_Period;
	};

	return NULL;
}


/* スレーブ選択関数 */
/* 選択が終了されるときFLASEを返す */
S4 SelectSlave(VD ){
    S4 select               = 0;
    S4 return_value         = TRUE;
    U1 buff[BUFF_SIZE]      = {0};     /*受信バッファ*/
    //文字列取得
    printf("master>");
    fgets(buff,BUFF_SIZE,stdin);

    //オーバーフロー時
    if(buff[strlen(buff)-1] != '\n'){
        while('\n' != getchar() );
    }

    //q が押された場合終了
    if( strcmp(buff,"q\n") == 0 || strcmp(buff,"\n") == 0){
        return_value = FALSE;
    }
    
    switch(atoi(buff)){
        case 1 : 
            data.SS1 = Lo;
            break;
        case 2 : 
            data.SS2 = Lo;
            break;
        case 3 :
            data.SS3 = Lo;
            break;
        default :
        /*Do Nothing*/
            break;
    }
    return return_value;
}