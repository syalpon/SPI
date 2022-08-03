#include "type.h"
#include "slave.h"
#include "spi.h"
#include <cstdio>
#include <windows.h>


/*�R���X�g���N�^*/
SLAVE_CLASS::SLAVE_CLASS()
{
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
    SLAVE_CLASS Slave;
    /*�o�X�ݒ�*/
    Slave.u1_S_CLK = ((U1 **)vp_arg)[0];
    Slave.u1_S_DO  = ((U1 **)vp_arg)[1];
    Slave.u1_S_DI  = ((U1 **)vp_arg)[2];
    Slave.u1_S_SS  = ((U1 **)vp_arg)[2+Slave.u4_object_number]; 

    /*�N��:�������[�v*/
    while(true){
        /*�G�b�W�̃E�H�b�`�h�b�O*/
        if( Slave.u1_EdgeDetection( *(Slave.u1_S_SS) ) == 1 )
        {
            
        }
        printf("test");
        Sleep(1000);
    }

    return NULL;
}

/*�G�b�W���o�֐�*/
U1 SLAVE_CLASS::u1_EdgeDetection(U1 u1_level)
{
    U1 active_now;
    U1 active_pre;

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
        /* TODO */ /*�Z���N�g��M��*/
    }

    /*�O��l�̍X�V*/
    this->u1_level_previous = u1_level;
    return 0;    
} 


