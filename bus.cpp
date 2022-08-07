#include <pthread.h> /*マルチスレッドに必要*/
#include <windows.h> /*Sleepに必要*/
#include "type.h"
#include "bus.h"

/*コンストラクタ*/
BUS_CLASS::BUS_CLASS()
{
    this->u1_address = nullptr;
}

BUS_CLASS::BUS_CLASS(U1 *addr)
{
    this->u1_address = addr;
    /*バス監視用スレッド起動*/
    pthread_t pt;
    if( pthread_create(&pt,nullptr,vp_ICU,(VP)addr) != 0 )
    {
            pthread_join(pt,nullptr);
    }
}


static VP vp_ICU(VP vp_arg)
{
    U1 u1_level_now = 0;
    U1 u1_level_pre = 0;
    U1 *u1p_bus = (U1 *)vp_arg;

    /*初期化*/
    u1_level_now = *u1p_bus;
    u1_level_pre = u1_level_now;
    /*10usポーリング*/
    while(true)
    {
        u1_level_now = *u1p_bus;
        /*エッジあり*/
        if(u1_level_now != u1_level_pre)
        {
            /*riging*/
            if(u1_level_now = 1)
            {
                
            }
            else
            {

            }
        }
        u1_level_pre = u1_level_now;
        Sleep(10);
    }
    return nullptr;
}