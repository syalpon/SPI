#include "type.h"
#include "slave.h"
#include "spi.h"
#include <cstdio>
#include <windows.h>


/*�R���X�g���N�^*/
SLAVE_CLASS::SLAVE_CLASS()
{
    SLAVE_CLASS(NULL);
}

SLAVE_CLASS::SLAVE_CLASS(VP vp_arg)
{
    /*�o�X�ݒ�*/
    this->u1_S_CLK = ((U1 **)vp_arg)[0];
    this->u1_S_DI  = ((U1 **)vp_arg)[1];
    this->u1_S_DO  = ((U1 **)vp_arg)[2];
    this->u1_S_SS  = ((U1 **)vp_arg)[2+this->u4_object_number]; 

    /*�����l�̐ݒ�*/
    U1 init_level;
    /*SPI_MODE�ɂ���ď����l��ς���*/
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



VP vp_slave_thrad(VP vp_arg)
{
    SLAVE_CLASS Slave(vp_arg);
    
    /*�X���b�h�N���x��*/
    Sleep(Slave.u4_object_number * 100);

    /*�N��:�������[�v*/
    while(true){
        /*�G�b�W�̃E�H�b�`�h�b�O*/
        while( Slave.u1_SS_ON() == 1 )
        {
            printf("slave%d::get\n",Slave.u4_object_number);
            if( Slave.u1_EdgeDetection( *(Slave.u1_S_CLK) ) == 1 )
            {
                printf("[%d]\n",Slave.u1_S_DO);
            }
        }
        
        Sleep(100);
    }

    return NULL;
}

/*�G�b�W���o�֐�*/
U1 SLAVE_CLASS::u1_EdgeDetection(U1 u1_level)
{
    U1 active_now;
    U1 active_pre;
    U1 retval = 0;
    /*������E�����G�b�W�̔���ݒ�(SPI_MODE�ɂ���ĕω�)*/
    if( ( SPI_MODE == 1 ) || ( SPI_MODE == 2 ) ) 
    {
        /*��������*/
        active_now = HIGH;
        active_pre = LOW;
    }
    else
    {
        /*���オ��*/
        active_now = LOW;
        active_pre = HIGH;
    }
    
    /*�G�b�W���o*/
    if( ( u1_level == active_now ) && ( this->u1_level_previous == active_pre ) )
    {
        retval = 1;
    }

    /*�O��l�̍X�V*/
    this->u1_level_previous = u1_level;
    return retval;
} 



U1 SLAVE_CLASS::u1_SS_ON()
{
    u1_EdgeDetection(*(this->u1_S_SS));
    return 0;
}
