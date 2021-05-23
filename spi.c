#include <stdio.h>
#include <pthread.h>
#include "define.h"
#include "spi.h"

/*グローバル変数*/
Data data;

/*外部関数宣言*/
extern void *master(void *);
extern void *slave1(void *);
extern void *slave2(void *);
extern void *slave3(void *);
extern void *slave4(void *);
extern void *clock_timer(void *);

/*データバス初期化*/
void data_init(void){
	data.sclk = Hi;
	data.simo = Lo;
	data.somi = Lo;
	data.ss0 = Hi;
	data.ss1 = Hi;
	data.ss2 = Hi;
	data.ss3 = Hi;
	data.ss4 = Hi;
}


/*SPI通信開始*/
void SPI_Start(void){
	//スレッド立ち上げ用変数
	pthread_t pt_master,pt_slave1,pt_slave2,pt_slave3,pt_clock;
	int ret0,ret1,ret2,ret3,ret4;

	//初期化
	data_init();

	//スレッド立ち上げ
	ret0 = pthread_create(& pt_master,NULL,master,NULL);
	ret1 = pthread_create(& pt_slave1,NULL,slave1,NULL);
	ret2 = pthread_create(& pt_slave2,NULL,slave2,NULL);
	ret3 = pthread_create(& pt_slave3,NULL,slave3,NULL);
	ret4 = pthread_create(& pt_clock ,NULL,clock_timer,NULL);

	/*スレッド立ち上げ失敗時*/
	if( ret0 || ret1 || ret2 || ret3 || ret4 ){
		printf("thread cleate Error\n");
	}else{
		/*マスタが終わるまで待機*/
		pthread_join(pt_master,NULL);
	}	
}