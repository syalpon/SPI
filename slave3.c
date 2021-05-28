/* --------------------------------
file:       slave3.c
brief:      スレーブ3
ver:        1.0.0   
-------------------------------- */
/*インクルードファイル*/
#include "spi.h"
#include "timer.h"
#include "type.h"
#include "define.h"
#include <stdio.h>

/*グローバル変数*/
extern Data data;
extern U1 Miso(U1 *);
extern U1 Simo(U1 *);
/*プロトタイプ宣言*/


/*------------------------------*/
VP slave3(VP p_data){
    U1 buff = 0;
    while(true){
        if(data.SS3 == Lo){
            printf("slave1 Receiving\n");
            buff = Simo(NULL);
            printf("slave1 Received : %x\n",buff);
            data.SS3 = Hi;
            Sleep_QuarterPeriod;
        }
        Sleep_QuarterPeriod;
    }
	return NULL;
} 