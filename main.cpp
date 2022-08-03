/*------インクルードファイル------*/
#include <pthread.h> /*マルチスレッドに必要*/
#include <cstdio>
#include "type.h"
#include "spi.h"
#include "master.h"
#include "slave.h"

/*------外部宣言------*/
/*スレッド起動で呼び出される関数へのポインタ*/
VP (*vp_thread_table[1+SLAVE_NUM])(VP);


/*------ファイル内グローバル変数------*/
/*クロックバス用メモリ*/
static U1 u1_CLK;
/*データバス用メモリ*/
static U1 u1_DO;
static U1 u1_DI;
/*スレーブセレクトバス用メモリ*/
static U1 u1_SS[SLAVE_NUM];
/*アドレステーブル*/
static U1 *addr_table[1+2+SLAVE_NUM];



/*------処理------*/
int main()
{
  	pthread_t pt[1+SLAVE_NUM];
    MASTER_CLASS Master;
    SLAVE_CLASS Slave[SLAVE_NUM];
    S4 ret[SLAVE_NUM+1];
    S4 ret_sum = 0;

    /*ブート処理*/
    addr_table[0] = &u1_CLK;
    addr_table[1] = &u1_DO;
    addr_table[2] = &u1_DI;
    for(U1 i=0 ; i<SLAVE_NUM ; i++ )
    {
        addr_table[3+i] = &u1_SS[i];
    }

    /*スレッド起動*/
    for(U1 i=0 ; i<1+SLAVE_NUM ; i++ )
    {
        ret[i] = pthread_create(&pt[i] ,NULL,vp_thread_table[i],(VP)addr_table);     /*スレーブ*/
        ret_sum += ret[i] ;
    }

	/*スレッド立ち上げ失敗時*/
	if( ret_sum != 0 ){
		printf("thread create error\n");
	}else{
		/*マスタが終わるまで待機*/
		pthread_join(pt[0],NULL);
	}

    return 0;
}
