/*------�C���N���[�h�t�@�C��------*/
#include <pthread.h> /*�}���`�X���b�h�ɕK�v*/
#include <cstdio>
#include "type.h"
#include "master.h"
#include "slave.h"

/*------�O���錾------*/
extern  VP vp_master_thrad(VP );
extern  VP vp_slave_thrad(VP );

/*------�t�@�C�����O���[�o���ϐ�------*/
static U1 u1_CLK;                                   /*�N���b�N�o�X�p������*/
static U1 u1_DO;                                    /*�f�[�^OUT�o�X�p������*/
static U1 u1_DI;                                    /*�f�[�^IN�o�X�p������*/
static U1 u1_SS[SLAVE_NUM];                         /*�X���[�u�Z���N�g�o�X�p������*/
static U1 *u1p_addr_table[1+2+SLAVE_NUM];           /*�A�h���X�e�[�u��*/

/*------����------*/
int main()
{
    pthread_t pt[THREAD_NUM];
    S4 ret[THREAD_NUM];
    S4 ret_sum = 0;

    /*���񏈗�*/
    u1p_addr_table[0] = &u1_CLK;
    u1p_addr_table[1] = &u1_DO;
    u1p_addr_table[2] = &u1_DI;
    for(U1 i=0 ; i<SLAVE_NUM ; i++ )
    {
        u1p_addr_table[3+i] = &u1_SS[i];
    }

    /*�X���b�h�N��*/
    ret[0] = pthread_create(&pt[0] ,NULL,(VP(*)(VP))vp_master_thrad,(VP)u1p_addr_table);     /*�}�X�^*/
    ret_sum += ret[0] ;
    for(U1 i=1 ; i<THREAD_NUM ; i++ )
    {
        ret[i] = pthread_create(&pt[i] ,NULL,(VP(*)(VP))vp_slave_thrad,(VP)u1p_addr_table);     /*�X���[�u*/
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
