#ifndef _SPI_H_
#define _SPI_H_

#include "type.h"

/*�N���b�N���g��(1kHz)*/
#define CLOCK_HZ (1000) 

/*SPI�ʐM�̃G�b�W�E�A�N�e�B�u���[�h�ݒ�*/
/* 0 : L actiove , L->H trigger */
/* 1 : L actiove , H->L trigger */
/* 2 : H actiove , H->L trigger */
/* 3 : H actiove , L->H trigger */
#define SPI_MODE ((U1)2) 

#endif