#include "type.h"
#include "master.h"
#include <cstdio>
#include <windows.h>

/*global�ϐ�*/ /*�}���`�X���b�h�p�֐��|�C���^*/
extern VP (*vp_thread_table[1+SLAVE_NUM])(VP);

/*�R���X�g���N�^*/
MASTER_CLASS::MASTER_CLASS()
{
    printf("master start\n [%d] : %p (vp_master)\n",this->u4_object_number,&this->vp_master);
    vp_thread_table[this->u4_object_number] = (VP(*)(VP))&(this->vp_master);
}


VP MASTER_CLASS::vp_master(VP vp_arg)
{
    /*�o�X�ݒ�*/
    u1_M_CLK = ((U1 **)vp_arg)[0];
    u1_M_DO  = ((U1 **)vp_arg)[1];
    u1_M_DI  = ((U1 **)vp_arg)[2];
    for(U1 i=0 ; i<SLAVE_NUM ; i++ )
    {
        u1_M_SS[i] = ((U1 **)vp_arg)[3+i];
    }

    /*�N��:�������[�v*/
    while(true)
    {

        printf("master start\n");

        Sleep(10);
    }

    return NULL;
}