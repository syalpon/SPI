/* --------------------------------
file:       data_io.c
brief:      データバスアクセスを行う関数群
ver:        1.0.0   
-------------------------------- */
/*インクルードファイル*/
#include "spi.h"
#include "timer.h"
#include "type.h"
#include "define.h"
#include <stdio.h>

/*外部宣言*/
extern Data data;

/*グローバル変数*/

/*プロトタイプ宣言*/
U1 Simo(U1 *);
U1 Miso(U1 *);
U1 Read(DataIo );
VD Write(U1,DataIo );
VD Sync(U1 );


/*------------------------------*/
/* 引数がNULLのときはSlaveで返値は読み込み時の値*/
U1 Simo(U1 *p_buff){
    U1 return_value = 0;

    /* salve  Input*/
    if(p_buff == NULL){
         return_value = Read(SIMO);
    }
    /* master Output */
    else{
        Write( *p_buff ,SIMO);
        Sleep_Period;
    }

    return return_value;
}


/* 引数がNULLのときはMaster */
U1 Miso(U1 *p_buff){
     U1 return_value = 0;

    /* salve  Input*/
    if(p_buff == NULL){
         return_value = Read(MISO);

    /* master Output */
    }else{
        Write( *p_buff ,MISO);
    }

    return return_value;   
}

/*Read*/
U1 Read(DataIo dataIo ){
    U1  return_value = 0;
    U1  buff = 0;
    U1  count;
    U1 mask;
    const U1 MSB_MASK = 0x80;

    for( count = 0 ; count < DATA_LENGTH ; count++ ){

         /* wait clock bit */
        Sync( data.CPHA );

        /*データ読み込み*/
        if( dataIo == SIMO ){
            buff = data.SIMO;
        }else if( dataIo == MISO ){
            buff = data.MISO;
        }

        /*ビットマスク用*/
        mask = (MSB_MASK >> count);
        
        /* read bit data */
        return_value |= (mask & ( buff << (DATA_LENGTH - 1 - count) ));
    }

    return return_value;
}


/*Write*/
VD Write(U1 msg,DataIo dataIo){
    S4 count;
    U1 mask;
    const U1 MSB_MASK = 0x80;

    for( count = 0 ; count < DATA_LENGTH ; count++ ){
        mask = MSB_MASK >> count;

        /* wait clock bit */
        Sync(~data.CPHA);
        
        /* deta set */
        data.SIMO = ( mask & msg ) >> (DATA_LENGTH - count - 1 ) ;
    }
    Sleep_Period;
}



/*クロック信号に同期して遅延させる関数*/
VD Sync(U1 cpha ){
    U1  cpol = data.CPOL;
    U1  old_sck = data.SCK;
    U1  now_sck = data.SCK;

    while( true ){
        now_sck = data.SCK;
        
        if( cpol == cpha && old_sck == Hi && now_sck == Lo){
            break;
        }

        if( cpol != cpha && old_sck == Lo && now_sck == Hi){
            break;
        }

        old_sck = now_sck;
        Sleep_QuarterPeriod;
    };

}
