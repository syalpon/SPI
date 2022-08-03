#ifndef _SLAVE_H_
#define _SLAVE_H_

#include "type.h"
#include "thread.h"
#include "object.h"

/*�X���[�u:���ʎq�𓾂�׃I�u�W�F�N�g�N���X���p��*/
class SLAVE_CLASS : public OBJECT_CLASS
{
public:
    SLAVE_CLASS(); /*�R���X�g���N�^*/
public:
    /*SPI�p*/
    U1 *u1_S_CLK;  /*�N���b�N�o�X�͋��ʂ̈׃|�C���^�ŋ��ʃ��������Q��*/
    U1 *u1_S_DO;   /*�f�[�^�o�X�͋��ʂ̈׃|�C���^�ŋ��ʃ��������Q��*/
    U1 *u1_S_DI;   /*�f�[�^�o�X�͋��ʂ̈׃|�C���^�ŋ��ʃ��������Q��*/
    U1 *u1_S_SS;   /*�X���[�u�Z���N�g�̃G�b�W���g���K�Ƀf�[�^�̎�M�E�|�[�����O*/

public:
    U1 u1_level_previous;       /*�G�b�W�O��l*/
    U1 u1_EdgeDetection(U1);    /*�G�b�W���o�֐�*/
};

#endif
