#ifndef _SLAVE_H_
#define _SLAVE_H_

#include "type.h"
#include "device.h"

/*�X���[�u:���ʎq�𓾂�׃I�u�W�F�N�g�N���X���p��*/
class SLAVE_CLASS : public DEVICE_CLASS
{
public:
    SLAVE_CLASS();      /*�R���X�g���N�^*/
    SLAVE_CLASS(VP);    /*�R���X�g���N�^*/

public:


public:
    U1 u1_level_previous;       /*�G�b�W�O��l*/
    U1 u1_EdgeDetection(U1);    /*�G�b�W���o�֐�*/
    U1 u1_SS_ON();
};

#endif
