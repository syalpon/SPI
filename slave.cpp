#include "type.h"
#include "slave.h"
#include "spi.h"
#include <cstdio>
#include <windows.h>

/*global変数*/ /*マルチスレッド用関数ポインタの配列*/
extern VP (*vp_thread_table[1+SLAVE_NUM])(VP);

/*コンストラクタ*/
SLAVE_CLASS::SLAVE_CLASS()
{
    /*マルチスレッドの設定*/
    printf("slave[%d] start\n%p (vp_master)\n",this->u4_object_number,&this->vp_slave);
    vp_thread_table[this->u4_object_number] = (VP(*)(VP))(&(this->vp_slave));

    U1 init_level;
    /*初期値の設定*/
    /*SPI_MODEによって初期値を変える*/
    if( ( SPI_MODE & (U1)0x02 ) == (U1)1 )
    {
        init_level = HIGH;
    }
    else
    {
        init_level = LOW;
    }
    this->u1_level_previous = init_level;
}

VP SLAVE_CLASS::vp_slave(VP vp_arg)
{
    /*バス設定*/
    u1_S_CLK = ((U1 **)vp_arg)[0];
    u1_S_DO  = ((U1 **)vp_arg)[1];
    u1_S_DI  = ((U1 **)vp_arg)[2];
    u1_S_SS  = ((U1 **)vp_arg)[2+this->u4_object_number]; 

    /*起動:無限ループ*/
    while(true){

        printf("slave[%d] start\n",this->u4_object_number);

        /*エッジのウォッチドッグ*/
        if( this->u1_EdgeDetection( *(this->u1_S_SS) ) == 1 )
        {
            printf("test");
        }

        Sleep(1);
    }

    return NULL;
}

/*エッジ検出関数*/
U1 SLAVE_CLASS::u1_EdgeDetection(U1 u1_level)
{
    U1 active_now;
    U1 active_pre;

    /*立下り・立上りエッジの判定設定(SPI_MODEによって変化)*/
    if( ( SPI_MODE == 1 ) || ( SPI_MODE == 2 ) ) 
    {
        /*立下がり*/
        active_now = HIGH;
        active_pre = LOW;
    }
    else
    {
        /*立上がり*/
        active_now = LOW;
        active_pre = HIGH;
    }
    
    /*エッジ検出*/
    if( ( u1_level == active_now ) && ( this->u1_level_previous == active_pre ) )
    {
        /* TODO */ /*セレクト受信時*/
    }

    /*前回値の更新*/
    this->u1_level_previous = u1_level;
    return 0;    
} 


