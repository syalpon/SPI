/* --------------------------------
file:       spi.c
brief:      SPI通信処理
ver:        1.0.0   
-------------------------------- */

/*インクルードファイル*/
#include <stdio.h>
#include <pthread.h>
#include "type.h"
#include "define.h"
#include "spi.h"

/*グローバル変数*/

/*外部宣言*/
extern VP master(VP );
extern VP slave1(VP );
extern VP slave2(VP );
extern VP slave3(VP );
extern VP slave4(VP );
extern VP clock_timer(VP );
extern Data data;

/*プロトタイプ宣言*/
VD data_init(Data_Attr);
VD SPI_Start(Data_Attr);

/*------------------------------*/

/*データバス初期化*/
VD data_init(Data_Attr data_attr){
	data.CPOL = data_attr.Mode.CPOL;
	data.CPHA = data_attr.Mode.CPHA;
	
	if( data.CPOL == Lo ){
		data.SCK = Lo;
	}else{
		data.SCK = Hi;
	}

	data.SS1 = Hi;
	data.SS2 = Hi;
	data.SS3 = Hi;

	data.SIMO = Lo;
	data.MISO = Lo;
}


/*SPI通信開始*/
VD SPI_Start(Data_Attr data_attr){
	//スレッド立ち上げ用変数
	pthread_t pt_master,pt_slave1,pt_slave2,pt_slave3,pt_clock;
	S4 ret0,ret1,ret2,ret3,ret4;

	//初期化
	data_init(data_attr);

	//スレッド立ち上げ
	ret0 = pthread_create(& pt_master,NULL,master,NULL);
	ret1 = pthread_create(& pt_slave1,NULL,slave1,NULL);
	ret2 = pthread_create(& pt_slave2,NULL,slave2,NULL);
	ret3 = pthread_create(& pt_slave3,NULL,slave3,NULL);
	ret4 = pthread_create(& pt_clock ,NULL,clock_timer,(VP)(&data_attr.Speed));

	/*スレッド立ち上げ失敗時*/
	if( ret0 || ret1 || ret2 || ret3 || ret4 ){
		printf("thread cleate Error\n");
	}else{
		/*マスタが終わるまで待機*/
		pthread_join(pt_master,NULL);
	}	
}