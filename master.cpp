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
    MASTER_CLASS Master;
    /*バス設定*/
    Master.u1_M_CLK = ((U1 **)vp_arg)[0];
    Master.u1_M_DO  = ((U1 **)vp_arg)[1];
    Master.u1_M_DI  = ((U1 **)vp_arg)[2];
    for(U1 i=0 ; i<SLAVE_NUM ; i++ )
    {
        Master.u1_M_SS[i] = ((U1 **)vp_arg)[3+i];
    }
    /*起動:無限ループ*/
    while(true)
    {
        printf("master start\n");

        Sleep(500);
    }

    return NULL;
}