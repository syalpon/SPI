/* --------------------------------
file:       main.c
brief:      エントリーポイント
ver:        1.0.0   
-------------------------------- */

/*インクルードファイル*/
#include "type.h"
#include "spi.h"

/*グローバル変数*/
Data data;

/*外部関数宣言*/
extern VD SPI_Start(Data_Attr);

/*プロトタイプ宣言*/
S4 main(VD);


/*------------------------------*/

/*メイン関数*/
S4 main(VD){
    Data_Attr data_attr = { Mode0, CLOCK_SPEED };
    /*SPI通信開始*/
    SPI_Start(data_attr);
}