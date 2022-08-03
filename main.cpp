/*------インクルードファイル------*/
#include <pthread.h> /*マルチスレッドに必要*/
#include <cstdio>
#include "type.h"
#include "master.h"
#include "slave.h"

/*------外部宣言------*/
extern  VP vp_master_thrad(VP );
extern  VP vp_slave_thrad(VP );

/*------ファイル内グローバル変数------*/
static U1 u1_CLK;                                   /*クロックバス用メモリ*/
static U1 u1_DO;                                    /*データOUTバス用メモリ*/
static U1 u1_DI;                                    /*データINバス用メモリ*/
static U1 u1_SS[SLAVE_NUM];                         /*スレーブセレクトバス用メモリ*/
static U1 *u1p_addr_table[1+2+SLAVE_NUM];           /*アドレステーブル*/

/*------処理------*/
int main()
{
    pthread_t pt[THREAD_NUM];
    S4 ret[THREAD_NUM];
    S4 ret_sum = 0;

    /*初回処理*/
    u1p_addr_table[0] = &u1_CLK;
    u1p_addr_table[1] = &u1_DO;
    u1p_addr_table[2] = &u1_DI;
    for(U1 i=0 ; i<SLAVE_NUM ; i++ )
    {
        u1p_addr_table[3+i] = &u1_SS[i];
    }

    /*スレッド起動*/
    ret[0] = pthread_create(&pt[0] ,NULL,(VP(*)(VP))vp_master_thrad,(VP)u1p_addr_table);     /*マスタ*/
    ret_sum += ret[0] ;
    for(U1 i=1 ; i<THREAD_NUM ; i++ )
    {
        ret[i] = pthread_create(&pt[i] ,NULL,(VP(*)(VP))vp_slave_thrad,(VP)u1p_addr_table);     /*スレーブ*/
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
