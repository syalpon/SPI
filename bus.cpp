#include <pthread.h> /*�}���`�X���b�h�ɕK�v*/
#include <windows.h> /*Sleep�ɕK�v*/
#include "type.h"
#include "bus.h"

/*�R���X�g���N�^*/
BUS_CLASS::BUS_CLASS()
{
    this->u1_address = nullptr;
}

BUS_CLASS::BUS_CLASS(U1 *addr)
{
    this->u1_address = addr;
    /*�o�X�Ď��p�X���b�h�N��*/
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

    /*������*/
    u1_level_now = *u1p_bus;
    u1_level_pre = u1_level_now;
    /*10us�|�[�����O*/
    while(true)
    {
        u1_level_now = *u1p_bus;
        /*�G�b�W����*/
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