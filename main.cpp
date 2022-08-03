/*------�C���N���[�h�t�@�C��------*/
#include <pthread.h> /*�}���`�X���b�h�ɕK�v*/
#include <cstdio>
#include "type.h"
#include "spi.h"
#include "master.h"
#include "slave.h"

/*------�O���錾------*/
/*�X���b�h�N���ŌĂяo�����֐��ւ̃|�C���^*/
VP (*vp_thread_table[1+SLAVE_NUM])(VP);


/*------�t�@�C�����O���[�o���ϐ�------*/
/*�N���b�N�o�X�p������*/
static U1 u1_CLK;
/*�f�[�^�o�X�p������*/
static U1 u1_DO;
static U1 u1_DI;
/*�X���[�u�Z���N�g�o�X�p������*/
static U1 u1_SS[SLAVE_NUM];
/*�A�h���X�e�[�u��*/
static U1 *addr_table[1+2+SLAVE_NUM];



/*------����------*/
int main()
{
  	pthread_t pt[1+SLAVE_NUM];
    MASTER_CLASS Master;
    SLAVE_CLASS Slave[SLAVE_NUM];
    S4 ret[SLAVE_NUM+1];
    S4 ret_sum = 0;

    /*�u�[�g����*/
    addr_table[0] = &u1_CLK;
    addr_table[1] = &u1_DO;
    addr_table[2] = &u1_DI;
    for(U1 i=0 ; i<SLAVE_NUM ; i++ )
    {
        addr_table[3+i] = &u1_SS[i];
    }

    /*�X���b�h�N��*/
    for(U1 i=0 ; i<1+SLAVE_NUM ; i++ )
    {
        ret[i] = pthread_create(&pt[i] ,NULL,vp_thread_table[i],(VP)addr_table);     /*�X���[�u*/
        ret_sum += ret[i] ;
    }

	/*�X���b�h�����グ���s��*/
	if( ret_sum != 0 ){
		printf("thread create error\n");
	}else{
		/*�}�X�^���I���܂őҋ@*/
		pthread_join(pt[0],NULL);
	}

    return 0;
}
