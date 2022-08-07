#include "type.h"
#include "master.h"
#include <cstdio>
#include <windows.h>

/*コンストラクタ*/
MASTER_CLASS::MASTER_CLASS()
{

}

VP vp_master_thrad(VP vp_arg)
{
    MASTER_CLASS Master(3+SLAVE_NUM);
    /*バス設定*/
    Master.u1_M_CLK = ((U1 **)vp_arg)[0];
    Master.u1_M_DO  = ((U1 **)vp_arg)[1];
    Master.u1_M_DI  = ((U1 **)vp_arg)[2];
    for(U1 i=0 ; i<SLAVE_NUM ; i++ )
    {
        Master.u1_M_SS[i] = ((U1 **)vp_arg)[3+i];
    }

    Sleep(1000);
    printf("MASTER>>3!\n");
    Sleep(1000);
    printf("MASTER>>2!\n");
    Sleep(1000);
    printf("MASTER>>1!\n");

    /*slave2と通信*/
    *(Master.u1_M_SS[2]) = 1;
    U1 clock_level=1;
    for(U1 i=0;i<12;i++)
    {
        *(Master.u1_M_CLK) = clock_level;
        clock_level = clock_level == 1?0:1;
        Sleep(500);
        printf("MASTER::[%d]\n",clock_level);
        *(Master.u1_M_DO) = clock_level;
        Sleep(500);
    }

    printf("MASTER>>fin!\n");
    Sleep(1000);
    
    return NULL;
}