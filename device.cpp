

#include "type.h"
#include "device.h"


/*�R���X�g���N�^*/
DEVICE_CLASS::DEVICE_CLASS()
{
    DEVICE_CLASS(1);
}

DEVICE_CLASS::DEVICE_CLASS(U4 u4_SS_num)
{
    /*���I�z��̃������m��*/
    U1 *u1p_M_SS = new U1[u1_SS_num];
}

/*�f�X�g���N�^*/
DEVICE_CLASS::~DEVICE_CLASS()
{
    /*���I�������̉��*/
    delete[] u1p_M_SS;
}