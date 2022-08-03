#ifndef _MASTER_H_
#define _MASTER_H_

#include "type.h"
#include "object.h"
#include "spi.h"


/*�}�X�^:���ʎq�𓾂�׃I�u�W�F�N�g�N���X���p��*/
class MASTER_CLASS:OBJECT_CLASS
{
public:
    MASTER_CLASS(); /*�R���X�g���N�^*/
public:
    /*�}���`�X���b�h�p*/
    VP vp_master(VP);

    /*SPI�p*/
    U1 *u1_M_CLK;           /*�N���b�N�o�X�͋��ʂ̈׃|�C���^�ŋ��ʃ��������Q��*/
    U1 *u1_M_DO;            /*�f�[�^�o�X�͋��ʂ̈׃|�C���^�ŋ��ʃ��������Q��*/
    U1 *u1_M_DI;            /*�f�[�^�o�X�͋��ʂ̈׃|�C���^�ŋ��ʃ��������Q��*/
    U1 *u1_M_SS[SLAVE_NUM]; /*�X���[�u�Z���N�g�̓X���[�u�̐������K�v*/

private:
};


#endif
